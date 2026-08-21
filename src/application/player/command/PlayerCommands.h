#pragma once
#include "player/PlayerClient.h"
#include <vector>
#include <string>

#define PC_PARAMS PlayerClient* pClient, const std::string& commandUsed, const std::vector<std::string>& args
namespace PlayerCommands
{
    void CheatCommand(PC_PARAMS);
    void NewsCommand(PC_PARAMS);
    void ReloadNewsCommand(PC_PARAMS);
    void PlaceTileTest(PC_PARAMS);
}