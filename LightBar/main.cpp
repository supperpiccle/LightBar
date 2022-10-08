#include <iostream>
#include "SessionManager.h"
#include "LedMatrix.h"
#include <Stock.h>
#include <filesystem>

std::unique_ptr<IStock> CreateStock(std::string Ticker)
{
    return std::make_unique<YahooStock>(Ticker);
}

int main(int argc, char** argv)
{
    if (Details::g_StockLogoCache.get() == nullptr)
    {
        Details::g_StockLogoCache = std::make_unique<Details::InternetPictureCache>(std::filesystem::temp_directory_path());
    }

    SessionManager manager;
    LedMatrix matrix;

    manager.Run(matrix);
}