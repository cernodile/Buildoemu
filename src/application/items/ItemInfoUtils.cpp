#include "ItemInfoUtils.h"
#include "items/ItemInfo.h"
#include <string>
#include <unordered_map>

ItemType ItemInfoUtils::StringToItemType(const std::string& type)
{
    static std::unordered_map<std::string, ItemType> types =
    {
        {"TYPE_FIST", ItemType::Fist},
        {"TYPE_WRENCH", ItemType::Wrench},
        {"TYPE_USER_DOOR", ItemType::UserDoor},
        {"TYPE_LOCK", ItemType::Lock},
        {"TYPE_SIGN", ItemType::Sign},
        {"TYPE_SFX_WITH_EXTRA_FRAME", ItemType::SfxWithExtraFrame},
        {"TYPE_BOOMBOX", ItemType::Boombox},
        {"TYPE_DOOR", ItemType::Door},
        {"TYPE_PLATFORM", ItemType::Platform},
        {"TYPE_BEDROCK", ItemType::Bedrock},
        {"TYPE_LAVA", ItemType::Lava},
        {"TYPE_NORMAL", ItemType::Normal},
        {"TYPE_BACKGROUND", ItemType::Background},
        {"TYPE_SEED", ItemType::Seed},
        {"TYPE_CLOTHES", ItemType::Clothes},
        {"TYPE_GEMS", ItemType::Gems}
    };

    return types[type];
}

TileCollisionType ItemInfoUtils::StringToTileCollisionType(const std::string& type)
{
    static std::unordered_map<std::string, TileCollisionType> types =
    {
        {"TILE_COLLISION_NONE", TileCollisionType::None},
        {"TILE_COLLISION_SOLID", TileCollisionType::Solid},
        {"TILE_COLLISION_JUMP_THROUGH", TileCollisionType::JumpThrough}
    };

    return types[type];
}

MaterialType ItemInfoUtils::StringToMaterialType(const std::string& type)
{
    static std::unordered_map<std::string, MaterialType> types = 
    {
        {"MATERIAL_WOOD", MaterialType::Wood},
        {"MATERIAL_GLASS", MaterialType::Glass}
    };

    return types[type];
}

TileVisualEffect ItemInfoUtils::StringToTileVisualEffect(const std::string& type)
{
    static std::unordered_map<std::string, TileVisualEffect> types =
    {
        {"VISUAL_EFFECT_NONE", TileVisualEffect::None}
    };

    return types[type];
}

ItemImageStorage ItemInfoUtils::StringToItemImageStorage(const std::string& type)
{
    static std::unordered_map<std::string, ItemImageStorage> types =
    {
        {"STORAGE_SINGLE_FRAME_IN_TILESHEET", ItemImageStorage::SingleFrameInTilesheet},
        {"STORAGE_SMART_EDGE", ItemImageStorage::SmartEdge },
        {"STORAGE_SMART_EDGE_HORIZ", ItemImageStorage::SmartEdgeHoriz },
    };

    return types[type];
}

BodyPart ItemInfoUtils::StringToBodyPart(const std::string& type)
{
    static std::unordered_map<std::string, BodyPart> types =
    {
        { "HAT", BodyPart::Hat },
        { "SHIRT", BodyPart::Shirt },
        { "PANTS", BodyPart::Pants },
        { "SHOES", BodyPart::Shoes },
        { "FACEITEM", BodyPart::FaceItem },
        { "HAND", BodyPart::Hand }  
    };

    return types[type];
}