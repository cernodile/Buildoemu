#pragma once
#include "world/World.h"
#include <iostream>
#include <list>

class WorldManager
{
public:
    ~WorldManager();

    /**
     * @brief Will get a world by name if one is loaded. In case the world is not loaded, we'll create/load a brand new one.
     * 
     * @param worldName World name we wish to get
     * @return A pointer to the world
     */
    World* GetOrRegisterWorld(const std::string& worldName);

private:
    /**
     * @brief Registers a world in memory and returns the pointer to it after.
     *        Will return nullptr on any error.
     * 
     * @param worldName Name of the world
     * @return Pointer to the world in the registry
     */
    World* RegisterWorld(const std::string& worldName);
    
    /**
     * @brief Will delete all worlds and erase them from the registry
     */
    void DeleteAndCleanupAllWorlds();

    std::list<World*> m_worlds{}; // not sure if our needs are so humble that using an unordered map would be faster... 
};