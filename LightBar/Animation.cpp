#include "Animation.h"

StockAnimation::StockAnimation(std::string Ticker)
	: m_Ticker(Ticker)
{
	Quote q(Ticker);
	//m_CurrentQuote = q.getStockQuote();
}

void StockAnimation::Draw(LedMatrixView* View)
{

	auto height = View->GetHeight();
	auto width = View->GetWidth();
	// Assuming display is 64x64

	//Top left 32x32 for ticker
	//bottom 32x64 price + arrow
	//Top right 32x32 logo

	//Area tickerArea;
	//tickerArea.x0 = 0;
	//tickerArea.y0 = 0;
	//tickerArea.x1 = 32;
	//tickerArea.y1 = 32;
	//View->CreateSubMatrix(tickerArea)->Write(m_Ticker);

	//Area logoArea = tickerArea;
	//logoArea.x = 32;
	//View->CreateSubMatrix(tickerArea)->ShowPicture(m_CurrentQuote.GetLogoPathForTicker(m_Ticker));

	//Area bottomArea;
	//bottomArea.x = 0;
	//bottomArea.y = 32;
	//bottomArea.length = 32;
	//bottomArea.width = 64;
	//auto bottomSubMatrix = View->CreateSubMatrix(tickerArea);

	//std::string stockPriceStr;
	//auto bottomTextWidth = bottomSubMatrix->GetTextLength(stockPriceStr);
	//Area bottomTextArea;
	//Area bottomArrowArea;

	//bottomTextArea.x = 0;
	//bottomTextArea.y = 32;
	//bottomTextArea.length = 32;
	//bottomTextArea.width = bottomTextWidth;

	//bottomArrowArea.x = bottomTextWidth;
	//bottomArrowArea.y = 32;
	//bottomArrowArea.length = 32;
	//bottomArrowArea.width = 32; // Pick some other more realistic size here.

	//bottomSubMatrix->CreateSubMatrix(bottomTextArea)->Write(stockPriceStr);
	//bottomSubMatrix->CreateSubMatrix(bottomArrowArea)->ShowPicture(m_LogoCache.GetLogoFile(m_Ticker));
}