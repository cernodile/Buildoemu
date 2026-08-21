#pragma once
#include <string>

struct Config
{
    int port = 16999;
    std::string cdnServerUrl = "";
    std::string cdnBaseDirectory = "";
    
    bool enableNews = true;
    std::string newsSource = "news.txt";
    std::string newsGazette = "";
};