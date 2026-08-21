#include "DedicatedServer.h"
#include "PlatformEnums.h"
#include "ServerApplication.h"
#include "enet/enet.h"
#include "player/PlayerClient.h"

bool DedicatedServer::Initialize(int port)
{
    if (enet_initialize() != 0)
    {
        LogError("WSA error, can't initialize dedicated ENet server for some reason");
        return false;
    }

    if (m_host != nullptr)
    {
        LogError("Why call this twice?");
        return false;
    }

    ENetAddress address{};
    address.port = port;
	enet_address_set_host(&address, "0.0.0.0");
    m_host = enet_host_create(&address, 32, 2, 0, 0);

    if (m_host == nullptr)
    {
        LogError("Can't initialize dedicated ENet server at port %d. The port could be already used?", port);
        return false;
    }

    m_host->checksum = enet_crc32;
    enet_host_compress_with_range_coder(m_host);

    LogMsg("Dedicated setup at port %d", port);
    return true;
}

void DedicatedServer::Tick()
{
    // we're not ready initializing yet
    if (m_host == nullptr)
    {
        return;
    }

    ENetEvent evt{};
    while(enet_host_service(m_host, &evt, 1))
    {
        switch (evt.type)
        {
        case ENET_EVENT_TYPE_CONNECT:
        {
            if (evt.peer == nullptr || evt.peer->data != nullptr )
            {
                continue;
            }

            PlayerClient* client = new PlayerClient();
            evt.peer->data = client;
            
            client->Initialize(evt.peer);
            GetApp()->GetPlayerManager().Push(client);
            break;
        }
        case ENET_EVENT_TYPE_DISCONNECT:
        {
            LogMsg("User disconnected");
            break;
        }
        case ENET_EVENT_TYPE_RECEIVE:
        {
            PlayerClient* client = (PlayerClient*)evt.peer->data;

            if (client == nullptr)
            {
                continue;
            }

            LogMsg("Got packet");

            client->HandleIncomingPacket(evt.packet);
        
            enet_packet_destroy(evt.packet);
            break;
        }
        default:
        {
            break;
        }
        }
    }
}