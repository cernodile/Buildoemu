#include "PlayerManager.h"

void PlayerManager::Push(PlayerClient* client)
{
    m_playerClients.push_back(client);
}

void PlayerManager::Erase(PlayerClient* client)
{
    for (auto it = m_playerClients.begin(); it != m_playerClients.end(); )
    {
        if (*it == nullptr)
        {
            ++it;
            continue;
        }

        if ((*it) == client)
        {
            it = m_playerClients.erase(it);
            break;
        }
        else
        {
            ++it;
        }
    }
}