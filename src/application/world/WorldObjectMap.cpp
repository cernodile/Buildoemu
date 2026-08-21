#include "WorldObjectMap.h"
#include "util/ResourceUtils.h"

int WorldObjectMap::GetMemEstimate()
{
	return (int)(m_objects.size()) * 24;
}

void WorldObjectMap::Serialize(uint8* buffer, int& offsetInOut, bool write)
{
    int listSize = m_objects.size();
    MemorySerialize(listSize, buffer, offsetInOut, write);
    MemorySerialize(m_uniqueNumberGen, buffer, offsetInOut, write);

    // TODO: read objects like for real
}