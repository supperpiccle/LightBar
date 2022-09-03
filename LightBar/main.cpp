#include <iostream>
#include "SessionManager.h"
#include "LedMatrix.h"
#include <Stock.h>

std::unique_ptr<IStock> CreateStock(std::string Ticker)
{
    return std::make_unique<Stock>(Ticker);
}

int main(int argc, char** argv)
{
    SessionManager manager;
    LedMatrix matrix;

    manager.Run(matrix);
}