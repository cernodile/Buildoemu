#include "PlatformPrecomp.h"
#include "Proton.h"
#include "FileSystem/FileManager.h"

// we seriously don't care that much about this stuff

FileManager g_fileMgr{};
FileManager* GetFileManager() { return &g_fileMgr; }


int GetPrimaryGLX() { return 0; }
int GetPrimaryGLY() { return 0; }

bool IsLargeScreen()
{
	return true; 
}

bool IsTabletSize()
{
	return false;
}