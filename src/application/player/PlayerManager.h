#pragma once
#include <list>
#include "PlayerClient.h"

/**
 * @brief Keeps track of online players. If I was feeling fancy I'd probably make this a singleton.
 */
class PlayerManager
{
public:
    /**
     * @brief Adds a PlayerClient to the end of the player list
     * 
     * @param client A player's PlayerClient we wish to add
     */
    void Push(PlayerClient* client);

    /**
     * @brief Erases a PlayerClient from the online players list
     * 
     * @param client A player's PlayerClient we wish to erase
     */
    void Erase(PlayerClient* client);

private:
    std::list<PlayerClient*> m_playerClients{};
};