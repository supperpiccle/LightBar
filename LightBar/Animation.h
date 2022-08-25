#pragma once
#include <string>
#include <memory>
#include <ILedMatrix.h>
#include <Stock.h>

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

class StockAnimation : public IAnimation
{
public:
	StockAnimation(std::string Ticker);

	void Draw(ILedMatrixView& View) override;

private:
	std::string m_Ticker;
	std::string m_LogoImagePath;
	std::unique_ptr<IStock> m_Stock;

	std::string GetStockPriceString();
};

// session manager picks session and runs it, then picks another.
// session handles that session.
