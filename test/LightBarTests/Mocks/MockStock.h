#include <Stock.h>
#include <queue>
#include <filesystem>

class MockStock : public IStock
{
public:

    MockStock() = default;
    ~MockStock() = default;

    MOCK_METHOD(std::string, Ticker, (), (override));
    MOCK_METHOD(double, Price, (), (override));
    MOCK_METHOD(unsigned int, Volume, (), (override));
    MOCK_METHOD(double, OpenPrice, (), (override));
    MOCK_METHOD(double, ClosePrice, (), (override));
    MOCK_METHOD(double, ChangeToday, (), (override));
    MOCK_METHOD(StockUpdateResult, Update, (), (override)); 
};

std::queue<std::unique_ptr<MockStock>> g_GlobalStockMocks;

std::unique_ptr<IStock> CreateStock(std::string Ticker)
{
    if (Details::g_StockLogoCache == nullptr)
    {
        Details::g_StockLogoCache = std::make_unique<Details::InternetPictureCache>(std::filesystem::temp_directory_path());
    }
    if (g_GlobalStockMocks.empty())
    {
        return std::make_unique<MockStock>();
    }
    else
    {
        auto ret = std::move(g_GlobalStockMocks.front());
        g_GlobalStockMocks.pop();
        return ret;
    }
}
