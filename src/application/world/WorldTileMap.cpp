#include "WorldTileMap.h"
#include "util/ResourceUtils.h"

int WorldTileMap::GetMemEstimate()
{
	return (int)(m_tiles.size()) * 16 + 102400;
}

void WorldTileMap::Serialize(uint8* buffer, int& offsetInOut, bool write)
{
    MemorySerialize(m_sizeX, buffer, offsetInOut, write);
    MemorySerialize(m_sizeY, buffer, offsetInOut, write);

    int tileCount = (int)m_tiles.size();
    LogMsg("tileCount=%d", tileCount);
    MemorySerialize(tileCount, buffer, offsetInOut, write);

    for (auto& tile : m_tiles)
    {
        tile.Serialize(buffer, offsetInOut, write);
    }
}

void WorldTileMap::CreateWorld()
{
    m_sizeX = 100;
    m_sizeY = 60;

    m_tiles.resize(6000);

    // highly advanced world generation by yours truly, gia.
    int index = 0;
    for (auto& tile : m_tiles)
    {
        index++;

        if (index <= 3000)
        {
            continue;
        }

        tile.SetItemID(2);
    }
}