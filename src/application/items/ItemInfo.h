#pragma once
#include "PlatformPrecomp.h"
#include "boost/signals2/last_value.hpp"

enum class ItemType
{
    Fist = 0,
    Wrench,
    UserDoor,
    Lock,
    Sign,
    SfxWithExtraFrame,
    Boombox,
    Door,
    Platform,
    Bedrock,
    Lava,
    Normal,
    Background,
    Seed,
    Clothes,
    Gems
};

enum class MaterialType
{
    Wood = 0,
    Glass
};

enum class TileVisualEffect
{
    None = 0
};

enum class ItemImageStorage
{
	SingleFrameInTilesheetAlone = 0,
    SingleFrameInTilesheet,
    SmartEdge,
    SmartEdgeHoriz
};

enum class TileCollisionType
{
    None = 0,
    Solid,
    JumpThrough
};

enum class BodyPart
{
    Hat = 0,
    Shirt,
    Pants,
    Shoes,
    FaceItem,
    Hand
};

#define C_MAX_SPLICE_SEEDS (2)

class ItemInfo
{
public:
    struct GrowInfo
    {	
        uint8 m_seedBaseImageFrame = 0;
        uint8 m_seedOverlayImageFrame = 0;
        uint8 m_treeBaseImageFrame = 0;
        uint8 m_treeOverlayImageFrame;
        uint32 m_baseColor = 0;
        uint32 m_overlayColor = 0;
        uint16 m_seed[C_MAX_SPLICE_SEEDS]{};
        uint32 m_secondsRequiredToBloom = 0;
        int m_maxFruit = 0;
        uint8 m_growMultiplier = 0;
    };

    void Serialize(uint8* buffer, int& offset, bool write, int version);
    void CalculateGrowImagesAndColors(int randomSeed);

    int m_itemID = -1;
    ItemType m_type = ItemType::Normal;
    MaterialType m_material = MaterialType::Wood;
    TileVisualEffect m_visual = TileVisualEffect::None;
    ItemImageStorage m_storage = ItemImageStorage::SingleFrameInTilesheet;
    TileCollisionType m_collision = TileCollisionType::None;

    std::string m_textureFile = "";
    uint32 m_textureFileHash = 0;
    uint8 m_frameX = 0;
    uint8 m_frameY = 0;

    std::string m_name = "";

    uint16 m_rarity = 0;
    int8 m_layer = 0;
    uint8 m_health = 0;
    uint8 m_maxCanHold = 99;
    int m_secondsToHeal = 0;
    uint32 m_color = MAKE_RGBA(255,255,255,255);

    BodyPart m_bodyPart = BodyPart::Hat;
    GrowInfo m_growInfo{};

    std::string m_extraFileName = "";
    uint32 m_extraFileHash = 0;
	int m_animMS = 400;
};