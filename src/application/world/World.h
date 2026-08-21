#pragma once
#include "PlatformSetup.h"
#include "world/WorldObjectMap.h"
#include "world/WorldTileMap.h"

class World
{
public:
    uint8* SaveToMem(int& offsetInOut);

    WorldTileMap * GetTileMap() { return &m_tileMap; }
    WorldObjectMap * GetObjectMap() { return &m_objectMap; }

    void SetName(const std::string& name) { m_name = name; }
    std::string GetName() const { return m_name; }
    
private:
    WorldTileMap m_tileMap{};
    WorldObjectMap m_objectMap{};
    std::string m_name = "";
};