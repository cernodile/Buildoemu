#include "PlatformEnums.h"
#include "PlatformPrecomp.h"
#include "ServerApplication.h"
#include "util/MiscUtils.h"
#include "util/ResourceUtils.h"
#include "util/TextScanner.h"

void LoadTextFile(std::string& lines, const std::string& fName)
{
	unsigned int size = 0;
	uint8* file = LoadFileIntoMemory(fName, &size, false);

	if (file  == nullptr)
	{
		return;
	}

	std::string str(reinterpret_cast<char*>(file ), strlen(reinterpret_cast<char*>(file)));

	lines = str;

	SAFE_DELETE_ARRAY(file );
}

void ServerApplication::LoadNews()
{
    LoadTextFile(m_config.newsGazette, "../server/" + m_config.newsSource);
}

bool ServerApplication::LoadConfig()
{
    TextScanner file(std::string("../server/config.txt"));
    
    if (!file.IsLoaded())
    {
        LogError("You're missing config.txt. You sure you're running this from a directory that can access ../server/config.txt?");
        return false;
    }

    m_config.port = StringToInt(file.GetParmString("port", 1));
    m_config.cdnServerUrl = file.GetParmString("cdn_server_url", 1);    
    m_config.cdnBaseDirectory = file.GetParmString("cdn_base_directory", 1);    
    m_config.newsSource = file.GetParmString("news_source", 1);
    m_config.enableNews = StringToInt(file.GetParmString("disable_news", 1)) == 0;

    LoadNews();

    LogMsg("Dedicated ENet server will be initialized under UDP port %d", GetConfig().port);
    return true;
}

bool ServerApplication::Initialize()
{
    if (!LoadConfig())
    {
        LogError("Can't load config.txt");
        return false;
    }

    if (!m_itemManager.Load())
    {
        LogError("Can't load item_definitions.txt");
        return false;
    }

    m_itemManager.InitializePlayerItemData();

    if (!m_dedicatedServer.Initialize(m_config.port))
    {
        LogError("Can't initialize ENet server");
        return false;
    }

    m_isTicking = true;
    return true;
}

void ServerApplication::Tick()
{
    m_dedicatedServer.Tick();
}