#pragma once
#include "world/WorldObject.h"
#include <vector>

#include "PlatformSetup.h"

class WorldObjectMap
{
public:
    int GetMemEstimate();
    void Serialize(uint8* buffer, int& offsetInOut, bool write);

private:
    uint32 m_uniqueNumberGen = 0;
    std::vector<WorldObject> m_objects{};
};