#pragma once
#include <thread>
#include <vector>
#include <string>
#include "Animation.h"
#include <ILedMatrix.h>
#include <condition_variable>
#include <deque>

class StockRequest
{
public:
	StockRequest();
	~StockRequest();

	void Issue(std::string Ticker);
	StockAnimation GetNext();

private:
	void ThreadFunction();
	std::thread m_Thread;
	std::deque<std::string> m_ToGetTickers;
	std::deque<StockAnimation> m_Stocks;
	std::mutex m_Mut;
	std::condition_variable m_Cv;
	bool m_Rundown = false;
};

class Session
{
public:
	Session() = default;
	~Session() = default;

	virtual void Signal() = 0;

private:
};

class StockSession : public Session
{
public:
	StockSession(std::vector<std::string> Tickers, ILedMatrix& Matrix);
	~StockSession();

	virtual void Signal() override;

private:
	void AnimationThread();
	bool m_Rundown;
	std::thread m_Thread;

	std::vector<IAnimation> m_Animations;

	ILedMatrix& m_Matrix;
	unsigned int m_CurrentStockIndex = 0;
	const unsigned int m_MillisecondsUpdate = 100;
	std::vector<std::string> m_Tickers;
};
