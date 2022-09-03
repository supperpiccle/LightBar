#include "Session.h"
#include <vector>
#include <queue>
#include <future>
#include <iostream>

struct StockAreaPack
{
    StockAnimation stock;
    Area area;
};

StockRequest::StockRequest()
{
    m_Thread = std::thread(&StockRequest::ThreadFunction, this);
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
    StockRequest stockRequestor;
    std::deque<StockAreaPack> stockPack;
    Area frontArea;
    Area totalArea;

    auto numInList = std::min(15, (int)m_Tickers.size());

    for(int i = 0; i < numInList; i++)
    {
        Area area;
        area.x0 = 0 - (64*i);
        area.x1 = 64 - (64*i);
        area.y0 = 0;
        area.y1 = 64;

        stockPack.push_back({StockAnimation("Crwd"), area});
    }

    frontArea = stockPack.front().area;

    if (frontArea.x0 == 0)
    {
        frontArea.x0 = -64;
        frontArea.x1 = 0;
    }

    totalArea.x0 = stockPack.front().area.x0;
    totalArea.x1 = stockPack.back().area.x1;
    totalArea.y0 = 0;
    totalArea.y1 = 64;

    //
    // Clear the matrix and get our root view.
    //
    m_Matrix.Clear();
    auto rootView = m_Matrix.CreateView();
    rootView->ClearSubViews();
    ILedMatrixView* tempView;
    for (auto& pack : stockPack)
    {
        auto& animationView = rootView->CreateSubMatrix(pack.area);
        pack.stock.Draw(animationView);
        tempView = &animationView;
    }
    stockRequestor.Issue("Crwd");
    while(!m_Rundown)
    {
        m_Matrix.Draw();
        tempView->Shift(0, 1);
        std::this_thread::sleep_for(std::chrono::milliseconds(m_MillisecondsUpdate));

        //
        // Move each animation up a pixel.  If any of them go past our panel, remove it.
        //
        //for (auto& pack : stockPack)
        //{
        //    auto& animationView = rootView->CreateSubMatrix(pack.area);
        //    pack.stock.Draw(animationView);
        //}
        //for (auto& pack : stockPack)
        //{
        //    pack.area.x0++;
        //    pack.area.x1++;
        //}
        //if (stockPack.back().area.x0 == 64)
        if (tempView->GetAbsoluteArea().x0 == 64)
        {
            stockPack.pop_back();
            stockPack.push_front({stockRequestor.GetNext(), frontArea});

            auto& animationView = rootView->CreateSubMatrix(frontArea);
            stockPack.front().stock.Draw(animationView);
            tempView = &animationView;
            stockRequestor.Issue("Crwd");
        }
    }
}

void StockSession::StockUpdateThread()
{

}