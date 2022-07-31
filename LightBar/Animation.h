#pragma once
#include <string>
#include "LedMatrix.h"
#include "quote.hpp"

struct AnimationSpace
{
	unsigned int x0;
	unsigned int y0;
	unsigned int x1;
	unsigned int y1;
};

struct AnimationMove
{
	unsigned int x;
	unsigned int y;
};

struct Pixel
{
	unsigned int X;
	unsigned int Y;
	unsigned char Red;
	unsigned char Green;
	unsigned char Blue;
};
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
	virtual void Draw(LedMatrixView* View) = 0;
};

class RainbowAnimation : public IAnimation
{

};

class WeatherAnimation : public IAnimation
{

};

class StockAnimation : public IAnimation
{
public:
	StockAnimation(std::string Ticker);

	void Draw(LedMatrixView* View) override;

private:
	std::string m_Ticker;
	StockQuote m_CurrentQuote = {0};
	std::string m_LogoImagePath;
	Details::StockLogoCache m_LogoCache;

	const unsigned int m_MillisecondsUpdate = 1000;

};

// session manager picks session and runs it, then picks another.
// session handles that session.
