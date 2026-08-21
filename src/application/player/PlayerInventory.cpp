#include "PlayerInventory.h"
#include "util/ResourceUtils.h"

void PlayerInventory::Serialize(uint8* buffer, int& offsetInOut, bool write)
{
    MemorySerialize(m_version, buffer, offsetInOut, write);

    if (write)
    {
        uint8 itemAmount = (uint8)m_items.size();
		MemorySerialize(itemAmount, buffer, offsetInOut, write);

		for (auto& item : m_items)
		{
			MemorySerialize(item.m_itemID, buffer, offsetInOut, write);
			MemorySerialize(item.m_count, buffer, offsetInOut, write);
			MemorySerialize(item.m_flags, buffer, offsetInOut, write);
		}
    }
    else
    {
        LogError("Reading player inventory is not supported because gia is a lazy prick.");
    }
}