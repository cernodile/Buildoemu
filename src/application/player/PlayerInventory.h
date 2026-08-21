#pragma once
#include "PlatformSetup.h"

class PlayerInventory
{
public:
    struct Item
    {
        int16 m_itemID = 0;
        uint8 m_count = 0;
        uint8 m_flags = 0;
    };

    void Serialize(uint8* buffer, int& offsetInOut, bool write);
    void Add(Item item) { m_items.push_back(item); }

private:
    uint8 m_version = 0;

    std::vector<Item> m_items{};
};