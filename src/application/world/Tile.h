#pragma once
#include "PlatformSetup.h"

class Tile
{
public:
    void Serialize(uint8* buffer, int & offsetInOut, bool write);
    void SetItemID(int itemID) { m_itemID= (uint16)itemID;}

private:
	uint16 m_itemID = 0;
	uint16 m_itemBGID = 0;
	uint16 m_flags = 0;
    uint16 m_parent = 0;
};