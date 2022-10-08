#pragma once
#include <string>
#include <memory>
#include <ILedMatrix.h>
#include <Stock.h>
#include <future>

struct DisplaySection
{
	DisplaySection(
		unsigned int X0,
		unsigned int Y0,
		unsigned int X1,
		unsigned int Y1
	) : X0(X0),
		Y0(Y0),
		X1(X1),
		Y1(Y1)

	{
	}
	unsigned int X0;
	unsigned int Y0;

	unsigned int X1;
	unsigned int Y1;
};

class IAnimation
{
	virtual void Draw(ILedMatrixView& View) = 0;
};

enum class StockUpdateStatus
{
	Success, Error, StillRunning
};

//
// TODO: The async nature of this class should make it
// non-movable
//
class StockAnimation : public IAnimation
{
public:
	StockAnimation(std::string Ticker);

	void Draw(ILedMatrixView& View) override;
	StockUpdateStatus DoStockUpdateAsync();
	std::string GetTicker();

private:
	std::string m_Ticker;
	std::string m_LogoImagePath;
	std::unique_ptr<IStock> m_Stock;

	std::string GetStockPriceString();
	std::future<void> m_UpdateStockTask;
};

// session manager picks session and runs it, then picks another.
// session handles that session.
