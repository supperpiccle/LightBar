#pragma once
#include <chrono>
#include <string>

enum class StockUpdateResult
{
    Success,
    Error
};

class IStock
{
public:
    virtual std::string Ticker() = 0;
    virtual double Price() = 0;
    virtual unsigned int Volume() = 0;
    virtual double OpenPrice() = 0;
    virtual double ClosePrice() = 0;
    virtual double ChangeToday() = 0;
    virtual StockUpdateResult Update() = 0;
};

std::unique_ptr<IStock> CreateStock(std::string Ticker);

class Stock : public IStock
{
public:
    Stock(const std::string& Ticker);

    virtual std::string Ticker() override;
    virtual double Price() override;
    virtual unsigned int Volume() override;
    virtual double OpenPrice() override;
    virtual double ClosePrice() override;
    virtual double ChangeToday() override;
    virtual StockUpdateResult Update() override;

private:

    std::string GetApiResponse();

    double m_CurrentPrice = 0;
    double m_OpenPrice = 0;
    double m_ClosePrice = 0;
    double m_HighPrice = 0;
    double m_LowPrice = 0;
    unsigned int m_Volume = 0;

    std::string m_Ticker;
    std::string m_ApiKey;
};


/*

    Stock stock("SPY");

    stock.Update();
    stock.price;
    stock.volume;

    stock.open_price
    stock.close_price
    stock.trading
    stock.options    
    stock.next_earnings_date.

    stock.CurrentPrice();
    stock.CurrentVolume();
*/