#include "PlayerCommandManager.h"
#include "player/command/PlayerCommands.h"
#include "util/MiscUtils.h"

PlayerCommandManager* PlayerCommandManager::Get()
{
    // lazy singleton
    static PlayerCommandManager mgr{};
    return &mgr;
}

PlayerCommandManager::PlayerCommandManager()
{
    AddCommand("cheat", PlayerCommands::CheatCommand);   
    AddCommand("news", PlayerCommands::NewsCommand);   
    AddCommand("reloadnews", PlayerCommands::ReloadNewsCommand);
}

void PlayerCommandManager::AddCommand(const std::string& name, std::function<void(PlayerClient*, const std::string&, const std::vector<std::string>&)> command)
{
    m_commands[name] = command;
}

void PlayerCommandManager::PerformCommand(PlayerClient* pClient, const std::string& input)
{
    if (pClient == nullptr)
    {
        return;
    }

    if (input.empty())
    {
        return;
    }

    std::vector<std::string> pieces = StringTokenize(input, " ");
    
    if (pieces.empty())
    {
        return;
    }

    std::string commandName = pieces[0];
    pieces.erase(pieces.begin());
    commandName.erase(commandName.begin());

    if (m_commands.find(commandName) != m_commands.end())
    {
        m_commands[commandName](pClient, commandName, pieces);
    }
    else
    {
        pClient->SendConsoleMessage("`4Unknown command!`` Type `w/?`` if you need help.");
    }
}