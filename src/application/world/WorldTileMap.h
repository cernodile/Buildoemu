#pragma once
#include <iostream>
#include <vector>
#include "Tile.h"
#include "PlatformSetup.h"

class WorldTileMap
{
public:
    int GetMemEstimate();
    void Serialize(uint8* buffer, int& offsetInOut, bool write);
    void CreateWorld();

private:
    int m_sizeX = 100;
    int m_sizeY = 60;
    std::vector<Tile> m_tiles{};
};