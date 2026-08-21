#pragma once
#include "items/ItemInfo.h"

namespace ItemInfoUtils
{
    ItemType StringToItemType(const std::string& type);
    TileCollisionType StringToTileCollisionType(const std::string& type);
    MaterialType StringToMaterialType(const std::string& type);
    TileVisualEffect StringToTileVisualEffect(const std::string& type);
    ItemImageStorage StringToItemImageStorage(const std::string& type);
    BodyPart StringToBodyPart(const std::string& type);
};