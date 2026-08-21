/**
 * @file Proton.h
 * @author gia
 * @brief Mostly unused functions proton needs.
 */
#pragma once
#include <iostream>

class FileManager;
FileManager* GetFileManager();


void AppendStringToFile(std::string filename, std::string text);
std::string GetDateAndTimeAsString();