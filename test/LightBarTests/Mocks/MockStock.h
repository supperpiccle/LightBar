#include <Stock.h>
#include <queue>

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
