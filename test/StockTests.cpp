/*
*	@Description Tests for stock quoting.
*	@author Justin Lewis
*/

#include <iostream>
#include <gtest/gtest.h>
#include "Stock.h"

TEST(BasicStockTests, GetCrwd) {
	Stock stock("crwd");

	std::cout << "Price: " << stock.Price() << std::endl;
	std::cout << "Open: " << stock.OpenPrice() << std::endl;
	std::cout << "Close: " << stock.ClosePrice() << std::endl;
	std::cout << "Change Today: " << stock.ChangeToday() << std::endl;
	std::cout << "Volume: " << stock.Volume() << std::endl;
}
