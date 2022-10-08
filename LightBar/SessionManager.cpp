#include <rapidjson/document.h>
#include "SessionManager.h"
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <Session.h>

SessionManager::SessionManager()
{

}

void SessionManager::Run(ILedMatrix& Matrix)
{
    std::ifstream f("/home/pi/LightBar/LightBar/LightBar/media/tickers.json");
    std::string line;
    std::stringstream completeFile;

    // Use a while loop together with the getline() function to read the file line by line
    while (std::getline(f, line)) 
    {
        completeFile << line;
    }

    rapidjson::Document doc;
    doc.Parse(completeFile.str().c_str());


    for (auto& entry : doc.GetArray())
    {
        std::string s = entry.GetString();
        m_Tickers.push_back(s);
    }

    StockSession session(m_Tickers, Matrix);
    std::this_thread::sleep_until(std::chrono::system_clock::now() + std::chrono::hours(std::numeric_limits<int>::max()));
    //std::this_thread::sleep_until(std::chrono::system_clock::now() + std::chrono::seconds(25));
}