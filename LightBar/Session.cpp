#include "Session.h"
#include <vector>
#include <queue>
#include <deque>

struct StockAreaPack
{
    StockAnimation stock;
    Area area;
};

StockSession::StockSession(std::vector<std::string> Tickers, ILedMatrix& Matrix)
    : m_Tickers(Tickers),
      m_Matrix(Matrix)
{
    m_Thread = std::thread(&StockSession::AnimationThread, this);
}

void StockSession::Signal()
{
}

void StockSession::AnimationThread()
{
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
        area.y1 = 0;

        stockPack.push_back({StockAnimation("Crwd"), area});
    }

    frontArea = stockPack.front().area;
    totalArea.x0 = stockPack.front().area.x0;
    totalArea.x1 = stockPack.back().area.x1;
    totalArea.y0 = 0;
    totalArea.y1 = 64;


    while(!m_Rundown)
    {
        //
        // Clear the matrix and get our root view.
        //
        m_Matrix.Clear();
        auto rootView = m_Matrix.CreateView();
        rootView->CreateSubMatrix(totalArea);

        for (auto& pack : stockPack)
        {
            auto& animationView = rootView->CreateSubMatrix(pack.area);
            pack.stock.Draw(animationView);
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(m_MillisecondsUpdate));

        //
        // Move each animation up a pixel.  If any of them go past our panel, remove it.
        //
        for (auto& pack : stockPack)
        {
            pack.area.x0++;
            pack.area.x1++;
        }
        if (stockPack.back().area.x0 == 64)
        {
            stockPack.pop_back();
            stockPack.push_front({StockAnimation("Crwd"), frontArea});
        }


    }
}