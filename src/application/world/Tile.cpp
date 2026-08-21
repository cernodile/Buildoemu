#include "Tile.h"
#include "util/ResourceUtils.h"

void Tile::Serialize(uint8* buffer, int & offsetInOut, bool write)
{
    MemorySerialize(m_itemID, buffer, offsetInOut, write);
    MemorySerialize(m_itemBGID, buffer, offsetInOut, write);
    MemorySerialize(m_parent, buffer, offsetInOut, write);
    MemorySerialize(m_flags, buffer, offsetInOut, write);
}