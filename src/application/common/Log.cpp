#include "PlatformPrecomp.h"
#include <cstdio>

static char g_logBuffer[4096]{};

//ugh, these might not compile on windows.

void LogMsg(const char* traceStr, ...)
{
    va_list list{};
    va_start(list, traceStr);
    vsprintf(g_logBuffer, traceStr, list);
    va_end(list);

    printf("%s\n", g_logBuffer);
}

void LogError(const char* traceStr, ...)
{
    va_list list{};
    va_start(list, traceStr);
    vsprintf(g_logBuffer, traceStr, list);
    va_end(list);

    printf("ERROR: %s\n", g_logBuffer);
}