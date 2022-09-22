/*
*	@Description Tests for stock quoting.
*	@author Justin Lewis
*/

#include <iostream>
#include <filesystem>
#include <gtest/gtest.h>
#include "Stock.h"

TEST(BasicStockTests, GetCrwd) {
    if (Details::g_StockLogoCache.get() == nullptr)
    {
        Details::g_StockLogoCache = std::make_unique<Details::InternetPictureCache>(std::filesystem::temp_directory_path());
    }
	Stock stock("crwd");

	std::cout << "Price: " << stock.Price() << std::endl;
	std::cout << "Open: " << stock.OpenPrice() << std::endl;
	std::cout << "Close: " << stock.ClosePrice() << std::endl;
	std::cout << "Change Today: " << stock.ChangeToday() << std::endl;
	std::cout << "Volume: " << stock.Volume() << std::endl;
}

TEST(BasicYahooStockTests, GetCrwd) {
    if (Details::g_StockLogoCache.get() == nullptr)
    {
		auto tempDir = std::filesystem::temp_directory_path();
        Details::g_StockLogoCache = std::make_unique<Details::InternetPictureCache>(tempDir.c_str());
    }
	YahooStock stock("crwd");

	std::cout << "Price: " << stock.Price() << std::endl;
	std::cout << "Open: " << stock.OpenPrice() << std::endl;
	std::cout << "Close: " << stock.ClosePrice() << std::endl;
	std::cout << "Change Today: " << stock.ChangeToday() << std::endl;
	std::cout << "Volume: " << stock.Volume() << std::endl;
}