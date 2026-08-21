#pragma once
#include "player/PlayerClient.h"
#include <iostream>
#include <unordered_map>
#include <functional>
#include <vector>

class PlayerCommandManager
{
public:
    PlayerCommandManager();
    static PlayerCommandManager* Get();

    void PerformCommand(PlayerClient* pClient, const std::string& input);
    void AddCommand(const std::string& name, std::function<void(PlayerClient*, const std::string&, const std::vector<std::string>&)> command);

private:
    std::unordered_map<std::string, std::function<void(PlayerClient*, const std::string&, const std::vector<std::string>&)>> m_commands{};
};