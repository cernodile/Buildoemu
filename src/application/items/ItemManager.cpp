#include "PlatformPrecomp.h"
#include "ItemManager.h"
#include "items/ItemInfo.h"
#include "items/ItemInfoUtils.h"
#include "util/MiscUtils.h"
#include "util/ResourceUtils.h"
#include "util/TextScanner.h"



uint32 StringToColor(const std::string& s)
{
	std::vector<std::string> piece = StringTokenize(s, ",");

	uint32 color = 0;

	if (piece.size() == 4)
	{
		color = MAKE_RGBA(StringToInt(piece[0]), StringToInt(piece[1]),
			StringToInt(piece[2]), StringToInt(piece[3]));
	}
	else
	{
		LogError("Badly formatted color: %s", s.c_str());
		color = 0;
	}

	return color;
}

void ItemManager::CreateSeedVersionOfLastItemAdded(int itemID)
{
	int originalID = itemID;
	itemID += 1;
	
	if (itemID + 1 >= m_items.size())
	{
		m_items.push_back(new ItemInfo());

		assert((itemID==m_items.size()-1));
	}

	ItemInfo& itemInfo = *m_items[itemID];
	ItemInfo tileInfo = *m_items[originalID];

	itemInfo = tileInfo;

	std::string name = "";

	itemInfo.m_itemID = itemID;
	itemInfo.m_type = ItemType::Seed;
	itemInfo.m_collision = TileCollisionType::None;
	itemInfo.CalculateGrowImagesAndColors(itemID / 2);
	itemInfo.m_health = 120;
	itemInfo.m_secondsToHeal = 2;
	itemInfo.m_visual = TileVisualEffect::None;
}

bool ItemManager::Load()
{
    TextScanner file(std::string("../server/item_definitions.txt"));

    if (!file.IsLoaded())
    {
        LogError("Couldn't load ../server/item_definitions.txt");
        return false;
    }

    int itemID = -1;

    for (int lineNum = 0; lineNum < file.GetLineCount(); lineNum++)
    {
        std::string line = file.GetLine(lineNum);

        if (line.empty() || line[0] == '#')
        {
            continue;
        }

        std::vector<std::string> pieces = StringTokenize(line, "|");

        if (pieces.empty())
        {
            continue;
        }

        std::string command = pieces[0];
        int itemID = -1;

        if (command == "add_item")
        {
			ItemInfo* pCurInfo = NULL;

			itemID = StringToInt(pieces[1]);

			if (itemID < m_items.size())
			{
				pCurInfo = m_items[itemID];
			}
			else
			{
				pCurInfo = new ItemInfo();

				m_items.push_back(pCurInfo);

				if (m_items.size() >= 3)
				{
					ItemInfo* pOldItem = m_items[m_items.size() - 3];

					if ((pOldItem->m_itemID + 2) != itemID)
					{
						LogError("ItemID's must be in order!");
						assert(!"ItemID's must be in order!");
						return false;
					}
				}
			}

            pCurInfo->m_itemID = StringToInt(pieces[1]);
            pCurInfo->m_name = pieces[2];
            pCurInfo->m_type = ItemInfoUtils::StringToItemType(pieces[3]);
            pCurInfo->m_material = ItemInfoUtils::StringToMaterialType(pieces[4]);
            pCurInfo->m_visual = ItemInfoUtils::StringToTileVisualEffect(pieces[5]);
            pCurInfo->m_storage = ItemInfoUtils::StringToItemImageStorage(pieces[6]);
            pCurInfo->m_frameX = (uint8)StringToInt(pieces[7]);
            pCurInfo->m_frameY = (uint8)StringToInt(pieces[8]);
            pCurInfo->m_textureFile = pieces[9];
            pCurInfo->m_textureFileHash = (uint32)std::stoull(pieces[10].c_str());
            pCurInfo->m_layer = (int8)StringToInt(pieces[11]);
            pCurInfo->m_collision = ItemInfoUtils::StringToTileCollisionType(pieces[12]);
            pCurInfo->m_health = (uint8)StringToInt(pieces[13]);
            pCurInfo->m_secondsToHeal = std::stoull(pieces[14].c_str());
            
			CreateSeedVersionOfLastItemAdded(itemID);
        }
        else if (command == "setup_seed")
        {
			itemID = StringToInt(pieces[1]);

			ItemInfo* pSeedInfo = m_items[itemID];

			pSeedInfo->m_growInfo.m_seed[0] = StringToInt(pieces[3]);
			pSeedInfo->m_growInfo.m_seed[1] = StringToInt(pieces[5]);
			pSeedInfo->m_growInfo.m_secondsRequiredToBloom = (uint32)std::stoull(pieces[7]);
			pSeedInfo->m_growInfo.m_maxFruit = (int)std::stoull(pieces[9]);

            uint32 baseColor = StringToColor(pieces[11]);
			if (baseColor != 0)
			{
				pSeedInfo->m_growInfo.m_baseColor = baseColor;
			}

			uint32 overlayColor = StringToColor(pieces[13]);
			if (overlayColor != 0)
			{
				pSeedInfo->m_growInfo.m_overlayColor = overlayColor;
			}
        }
        else if (command == "add_clothes")
        {            
			ItemInfo* pCurInfo = NULL;

			itemID = StringToInt(pieces[1]);

			if (itemID < m_items.size())
			{
				pCurInfo = m_items[itemID];
			}
			else
			{
				m_items.push_back(new ItemInfo());

				pCurInfo = m_items[itemID];

				if (m_items.size() >= 3)
				{
					ItemInfo* oldItem = m_items[m_items.size() - 3];

					if ((oldItem->m_itemID + 2) != itemID)
					{
						LogError("ItemID's must be in order! itemID=%d pieces[1]=%s", itemID, pieces[1].c_str());
						assert("ItemID's must be in order!");
						return false;
					}
				}
			}

			pCurInfo->m_itemID = itemID;
			pCurInfo->m_name = pieces[2];
			pCurInfo->m_type = ItemInfoUtils::StringToItemType(pieces[3]);
			pCurInfo->m_visual = ItemInfoUtils::StringToTileVisualEffect(pieces[4]);
			pCurInfo->m_storage = ItemInfoUtils::StringToItemImageStorage(pieces[5]);
			pCurInfo->m_frameX = (uint8)StringToInt(pieces[6]);
			pCurInfo->m_frameY = (uint8)StringToInt(pieces[7]);
			pCurInfo->m_textureFile = pieces[8];
			pCurInfo->m_textureFileHash = StringToInt(pieces[9]);
			pCurInfo->m_bodyPart = ItemInfoUtils::StringToBodyPart(pieces[10]);
			CreateSeedVersionOfLastItemAdded(itemID);
        }
		else if (command == "set_max_can_hold")
		{
			m_items[StringToInt(pieces[1])]->m_maxCanHold = StringToInt(pieces[2]);
		}
    }

    LogMsg("%d item definitions loaded.", (int)m_items.size());
    return true;
}


uint8* ItemManager::SaveToMem(uint32& sizeOut, uint16 itemDataVersion)
{
	uint8* buffer = new uint8[sizeof(ItemInfo) * (m_items.size())];

    int offset = 0;
	MemorySerialize(itemDataVersion, buffer, offset, true);

	int count = (int)m_items.size();
	MemorySerialize(count, buffer, offset, true);

	for (ItemInfo* pItemInfo : m_items)
	{
		pItemInfo->Serialize(buffer, offset, true, itemDataVersion);
	}

    sizeOut = (uint32) offset;

	return buffer;
}
    
void ItemManager::InitializePlayerItemData()
{
    constexpr int ITEM_DATA_VERSION = 1;

    //TODO: get file hashes
    // I won't bother supporting ogg item data as we don't have a buildo client for android anyway.
    m_itemData.data = SaveToMem(m_itemData.size, ITEM_DATA_VERSION);
    m_itemData.hash = HashString((const char*)m_itemData.data, m_itemData.size);

    LogMsg("Initialized player item data. Hash is %u, size %d.", m_itemData.hash, m_itemData.size);
}