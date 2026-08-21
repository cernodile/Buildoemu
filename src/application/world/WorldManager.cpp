#include "WorldManager.h"
#include "world/World.h"

WorldManager::~WorldManager()
{
    DeleteAndCleanupAllWorlds();
}

void WorldManager::DeleteAndCleanupAllWorlds()
{
    for (World* world : m_worlds)
    {
        if (world == nullptr)
        {
            continue;
        }   

        SAFE_DELETE(world);
    }

    m_worlds.clear();
}

World* WorldManager::GetOrRegisterWorld(const std::string& worldName)
{
    for (World* world : m_worlds)
    {
        if (world->GetName() == worldName)
        {
            return world;
        }
    }

    return RegisterWorld(worldName);
}

World* WorldManager::RegisterWorld(const std::string& worldName)
{
    if (worldName.empty())
    {
        return nullptr;
    }

    World* world = new World();    
    world->SetName(worldName);

    // TODO: Remove this soon.
    world->GetTileMap()->CreateWorld();
    //////

    m_worlds.push_back(world);
    return world;
}