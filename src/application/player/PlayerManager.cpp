#include "PlayerManager.h"

void PlayerManager::Push(PlayerClient* client)
{
    m_playerClients.push_back(client);
}

void PlayerManager::Erase(PlayerClient* client)
{
    //TODO: add this inabit
}