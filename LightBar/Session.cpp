#include "Session.h"
#include <vector>
#include <queue>
#include <future>
#include <iostream>
#include <algorithm>
#include <execution>

struct StockAreaPack
{
    StockAnimation& stock;
    ILedMatrixView& view;
};

StockRequest::StockRequest()
{
}
StockRequest::~StockRequest()
{
    m_Rundown = true;
    m_ToGetTickers.push_back("");
    m_Cv.notify_all();

    if(m_Thread.joinable())
    {
        m_Thread.join();
    }
}
void StockRequest::Issue(std::string Ticker)
{
    {
        std::lock_guard<std::mutex> lck(m_Mut);
        m_ToGetTickers.push_back(Ticker);
    }
    m_Cv.notify_all();
}

StockAnimation StockRequest::GetNext()
{
    std::unique_lock<std::mutex> lck(m_Mut);
    m_Cv.wait(lck, [this](){return !m_Stocks.empty();});

    auto ret = std::move(m_Stocks.front());
    m_Stocks.pop_front();
    return ret;
}

void StockRequest::ThreadFunction()
{
    while(!m_Rundown)
    {
        std::string nextTicker;
        {
            std::unique_lock<std::mutex> lck(m_Mut);
            m_Cv.wait(lck, [this](){return !m_ToGetTickers.empty();});

            nextTicker = m_ToGetTickers.front();
            m_ToGetTickers.pop_front();
        }

        {
            StockAnimation animation(nextTicker);
            std::lock_guard<std::mutex> lck(m_Mut);
            m_Stocks.push_back(std::move(animation));
        }

        m_Cv.notify_all();
    }
}

StockSession::StockSession(std::vector<std::string> Tickers, ILedMatrix& Matrix)
    : m_Tickers(Tickers),
      m_Matrix(Matrix),
      m_Rundown(false)
{
    m_Thread = std::thread(&StockSession::AnimationThread, this);
}
StockSession::~StockSession()
{
    Signal();
}

void StockSession::Signal()
{
    m_Rundown = true;
    if (m_Thread.joinable())
    {
        m_Thread.join();
    }
}

void StockSession::AnimationThread()
{
    std::deque<StockAreaPack> stockPack;
    Area backArea;
    Area frontArea;

    std::vector<std::string> tickers = {"CRWD", "MSFT", "IBM", "AMD", "SU", "GME", "INTC", "APPL", "CRSR", "RF", "SPDR", "JJ"};
    std::vector<StockAnimation> animations;

    animations.reserve(tickers.size());

    //
    // Clear the matrix and get our root view.
    //
    m_Matrix.Clear();
    std::mutex mut;

    std::for_each(std::execution::par,
                  tickers.begin(), tickers.end(),
                  [&mut, &animations](std::string Ticker)
                  {
                      StockAnimation animation(Ticker);
                      std::lock_guard<std::mutex> lck(mut);
                      animations.push_back(std::move(animation));
                  });

    for(int i = 0; i < tickers.size(); i++)
    {
        Area area;
        area.x0 = -64 - (48*i);
        area.x1 = 0 - (48*i);
        area.y0 = 0;
        area.y1 = 64;

        auto animationView = m_Matrix.CreateView();
        animationView->SetAbsoluteArea(area);
        stockPack.push_back(StockAreaPack{animations[i], *animationView});
    }
    for (auto& pack : stockPack)
    {
        pack.stock.Draw(pack.view);
    }

    backArea = stockPack.back().view.GetAbsoluteArea();
    frontArea = stockPack.front().view.GetAbsoluteArea();
    auto shiftLength = backArea.x0 - frontArea.x0;

    while(!m_Rundown)
    {
        m_Matrix.Draw();
        for (auto& pack : stockPack)
        {
            pack.view.Shift(0, 1);
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(m_MillisecondsUpdate));

        if (stockPack.front().view.GetAbsoluteArea().x0 == 64)
        {
            auto offscreenPack = stockPack.front();
            stockPack.pop_front();

            //
            // When we put this in the back issue a stock update.
            //
            auto result = offscreenPack.stock.DoStockUpdateAsync();
            if (result == StockUpdateStatus::StillRunning)
            {
                std::cout << "Ticker " << offscreenPack.stock.GetTicker() << " already updating!\n";
            }

            int extraShift = stockPack.size() > 1 ? 64 : 128;
            offscreenPack.view.Shift(0, shiftLength - extraShift);
            stockPack.push_back(offscreenPack);
        }
    }
}