#include "PlatformEnums.h"
#include "ServerApplication.h"
#include <chrono>
#include <thread>

static ServerApplication g_application{};

ServerApplication* GetApp()
{
    return &g_application;
}

int main(int argc, char** argv)
{
    LogMsg("Buildo Server Emulator by Gia");

    if (!g_application.Initialize())
    {
        LogError("Shame, application couldn't initialize itself :(");
        return 0;
    }

    while (g_application.IsTicking())
    {
        g_application.Tick();
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
}