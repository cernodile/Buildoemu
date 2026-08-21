#pragma once
#include "DedicatedServer.h"
#include "common/Config.h"
#include "items/ItemManager.h"
#include "player/PlayerManager.h"

/**
 * @brief Application class for the server
 */
class ServerApplication
{
public:
    bool Initialize();

    bool IsTicking() const { return m_isTicking; }
    void Tick();

    Config& GetConfig() { return m_config; }
    DedicatedServer& GetDedicatedServer() { return m_dedicatedServer; }
    PlayerManager& GetPlayerManager() { return m_playerManager; }
    ItemManager& GetItemManager() { return m_itemManager; }
    
    void LoadNews();
    
private:
    bool LoadConfig();

    bool m_isTicking = false;
    Config m_config{};
    DedicatedServer m_dedicatedServer{};
    PlayerManager m_playerManager{};
    ItemManager m_itemManager{};
};

ServerApplication* GetApp();