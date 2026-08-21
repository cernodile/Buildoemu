#pragma once
#include "enet/enet.h"

class DedicatedServer
{
public:
    bool Initialize(int port);
    void Tick();

private:
    ENetHost* m_host = nullptr;

};