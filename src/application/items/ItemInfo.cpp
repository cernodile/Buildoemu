#include "ItemInfo.h"
#include "util/CRandom.h"
#include "util/ResourceUtils.h"

uint32 GetBrightColorWithSeededRandom(CRandom& r)
{
	int random1 = r.Random(2);
	int random2 = r.Random(3);

	int rgba[4] = { 0 };

	int colorPaletIndicator = 0;

	if (random2 == 0)
	{
		random2 = r.Random(150);
		random2 += 105; // makes the color brighter
		colorPaletIndicator = random1 % 3;
		rgba[colorPaletIndicator] = random2;
	}
	else
	{
		random2 = r.Random(80);
		random2 += 175;
		colorPaletIndicator = random1 % 3;
		rgba[colorPaletIndicator] = random2;
	}

	uint32 random3 = r.Random(355U - random2);
	int result = 255;
	if (random3 < 256)
	{
		result = r.Random(355U - random2);
	}

	rgba[(random1 + 1) % 3] = result;

	int populator = 455 - (result + rgba[colorPaletIndicator]);
	random3 = r.Random(populator);
	random2 = 255;
	if (random3 < 256)
	{
		random2 = r.Random(populator);
	}

	rgba[(random1 + 2) % 3] = random2;

	// So here we do this... then we do a little bit of that, and it all makes sense!
	return (uint32)(rgba[2] * 0x1000000 + rgba[0] * 0x100 + 0xff + rgba[1] * 0x10000); // this is probably just MAKE_RGB but wna be sure
}

void ItemInfo::CalculateGrowImagesAndColors(int randomSeed)
{
    CRandom random{};
	random.SetRandomSeed(randomSeed);
	m_growInfo.m_baseColor = GetBrightColorWithSeededRandom(random);
	m_growInfo.m_overlayColor = GetBrightColorWithSeededRandom(random);

	uint8 imageSeed = randomSeed >> 31;

	m_growInfo.m_seedBaseImageFrame = (randomSeed + (imageSeed >> 4) & 15) - (imageSeed >> 4);
	m_growInfo.m_seedOverlayImageFrame = (randomSeed + (imageSeed >> 5) & 7) - (imageSeed >> 4);

	imageSeed = randomSeed * 2;
	uint8 slotSeed = randomSeed * 2 >> 31;

	m_growInfo.m_treeBaseImageFrame = (imageSeed + (slotSeed >> 5) & 7) - (slotSeed >> 5);
	m_growInfo.m_treeOverlayImageFrame = (imageSeed + (slotSeed >> 4) & 15) - (slotSeed >> 4);
}

void ItemInfo::Serialize(uint8* buffer, int& offset, bool write, int version)
{
    MemorySerialize(m_itemID, buffer, offset, write);
    
	uint8 type = (uint8)m_type;
	MemorySerialize(type, buffer, offset, write);
	m_type = (ItemType)type;

	uint8 material = (uint8)m_material;
	MemorySerialize(material, buffer, offset, write);
	m_material = (MaterialType)material;

    MemorySerialize(m_name, buffer, offset, write);

    MemorySerialize(m_textureFile, buffer, offset, write);
    MemorySerialize(m_textureFileHash, buffer, offset, write);
	
	uint8 visualType = (uint8)m_visual;
	MemorySerialize(visualType, buffer, offset, write);
	m_visual = (TileVisualEffect)visualType;

    MemorySerialize(m_color, buffer, offset, write);
    MemorySerialize(m_frameX, buffer, offset, write);
    MemorySerialize(m_frameY, buffer, offset, write);
    
	uint8 imageStorage = (uint8)m_storage;
	MemorySerialize(imageStorage, buffer, offset, write);
	m_storage = (ItemImageStorage)imageStorage;

    MemorySerialize(m_layer, buffer, offset, write);
    
	uint8 collisionType = (uint8)m_collision;
	MemorySerialize(collisionType, buffer, offset, write);
	m_collision = (TileCollisionType)collisionType;
    
    MemorySerialize(m_health, buffer, offset, write);
    MemorySerialize(m_secondsToHeal, buffer, offset, write);
    
	uint8 bodyPart = (uint8)m_bodyPart;
	MemorySerialize(bodyPart, buffer, offset, write);
	m_bodyPart = (BodyPart)bodyPart;
    
	MemorySerialize(m_rarity, buffer, offset, write);
	MemorySerialize(m_maxCanHold, buffer, offset, write);
	MemorySerialize(m_extraFileName, buffer, offset, write);
	MemorySerialize(m_extraFileHash, buffer, offset, write);
	MemorySerialize(m_animMS, buffer, offset, write);

  	MemorySerialize(m_growInfo.m_seedBaseImageFrame, buffer, offset, write);
	MemorySerialize(m_growInfo.m_seedOverlayImageFrame, buffer, offset, write);
	MemorySerialize(m_growInfo.m_treeBaseImageFrame, buffer, offset, write);
	MemorySerialize(m_growInfo.m_treeOverlayImageFrame, buffer, offset, write);
	MemorySerialize(m_growInfo.m_baseColor, buffer, offset, write);
	MemorySerialize(m_growInfo.m_overlayColor, buffer, offset, write);

    //seems to write the splicers too :d
    MemorySerialize(m_growInfo.m_seed[0], buffer, offset, write);
    MemorySerialize(m_growInfo.m_seed[1], buffer, offset, write);

	MemorySerialize(m_growInfo.m_secondsRequiredToBloom, buffer, offset, write);
}