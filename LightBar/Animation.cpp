#include "Animation.h"
#include <sstream>
#include <string>
#include <iomanip>

StockAnimation::StockAnimation(std::string Ticker)
	: m_Ticker(Ticker)
{
	m_Stock = CreateStock(m_Ticker);
}

void StockAnimation::Draw(ILedMatrixView& View)
{

	// Assuming display is 64x64

	//Top left 32x32 for ticker
	//bottom 32x64 price + arrow
	//Top right 32x32 logo

	auto height = View.GetHeight();
	auto width = View.GetWidth();

	/*
	-----------------
	Ticker   |   Logo
	-----------------
	Price|<Arrow>
	-----------------
	*/

	Area tickerArea;
	tickerArea.x0 = 0;
	tickerArea.y0 = 0;
	tickerArea.x1 = width / 2;
	tickerArea.y1 = height / 2;
	View.CreateSubMatrix(tickerArea).Write(m_Ticker);

	Area logoArea = tickerArea;
	logoArea.x0 = tickerArea.x1;
	logoArea.y0 = 0;
	logoArea.x1 = width;
	logoArea.y1 = height / 2;
	View.CreateSubMatrix(logoArea).Write("Picture");

	Area bottomArea;
	bottomArea.x0 = 0;
	bottomArea.y0 = tickerArea.y1;
	bottomArea.x1 = width;
	bottomArea.y1 = height;
	auto& bottomSubMatrix = View.CreateSubMatrix(bottomArea);

	std::string stockPriceStr = GetStockPriceString();
	auto bottomTextWidth = bottomSubMatrix.GetTextLength(stockPriceStr);
	Area bottomTextArea;
	Area bottomArrowArea;

	bottomTextArea.x0 = 0;
	bottomTextArea.y0 = 0;
	bottomTextArea.x1 = bottomTextWidth;
	bottomTextArea.y1 = bottomSubMatrix.GetHeight();

	bottomArrowArea.x0 = bottomTextArea.x1;
	bottomArrowArea.y0 = 0;
	bottomArrowArea.x1 = bottomArrowArea.x0 + (bottomSubMatrix.GetWidth() - bottomTextWidth);
	bottomArrowArea.y1 = 8;

	bottomSubMatrix.CreateSubMatrix(bottomTextArea).Write(stockPriceStr);

	std::string arrowPath;
	if (m_Stock->Price() > m_Stock->OpenPrice())
	{
		arrowPath = "/home/pi/LightBar/LightBar/build/media/up_arrow.png";
	}
	else if (m_Stock->Price() < m_Stock->OpenPrice())
	{
		arrowPath = "/home/pi/LightBar/LightBar/build/media/down_arrow.png";
	}
	else
	{
		arrowPath = "/home/pi/LightBar/LightBar/build/media/sideways_arrow.png";
	}
	bottomSubMatrix.CreateSubMatrix(bottomArrowArea).ShowPicture(arrowPath);
	//bottomSubMatrix.CreateSubMatrix(bottomArrowArea).Write("Arrow");

}

std::string StockAnimation::GetStockPriceString()
{
	std::stringstream stream;
	stream << std::fixed << std::setprecision(2) << m_Stock->Price();
	return stream.str();
}