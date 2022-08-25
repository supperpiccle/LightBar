#pragma once
#include <thread>
#include <vector>
#include <string>
#include "Animation.h"
#include <ILedMatrix.h>

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
	StockSession(std::vector<std::string> Tickers, ILedMatrix& Matrix);

	virtual void Signal() override;

private:
	void AnimationThread();
	bool m_Rundown;
	std::thread m_Thread;

	std::vector<IAnimation> m_Animations;

	ILedMatrix& m_Matrix;
	unsigned int m_CurrentStockIndex = 0;
	const unsigned int m_MillisecondsUpdate = 1000;
	std::vector<std::string> m_Tickers;
};
