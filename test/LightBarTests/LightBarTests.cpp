#include <gtest/gtest.h>
#include <Animation.h>
#include "Mocks/MockILedMatrixView.h"
#include "Mocks/MockStock.h"


using ::testing::Return;
using ::testing::ReturnRef;
using ::testing::StrEq;

bool operator==(const Area& lhs, const Area& rhs)
{
    return lhs.x0 == rhs.x0 &&
           lhs.x1 == rhs.x1 &&
           lhs.y0 == rhs.y0 &&
           lhs.y1 == rhs.y1;
}


TEST(StockSessionTests, StockSession64x64) {
    std::unique_ptr<MockStock> stock = std::make_unique<MockStock>();
    MockLedMatrixView view;
    MockLedMatrixView tickerView;
    MockLedMatrixView logoView;
    MockLedMatrixView bottomView;
    MockLedMatrixView priceView;
    MockLedMatrixView arrowView;
    auto priceTextWidth = 12;

    ON_CALL(view, GetHeight).WillByDefault(Return(64));
    ON_CALL(view, GetWidth).WillByDefault(Return(64));

    ON_CALL(*stock, Price()).WillByDefault(Return(100));
    ON_CALL(*stock, OpenPrice()).WillByDefault(Return(95));
    g_GlobalStockMocks.push(std::move(stock));

	Area tickerArea;
	tickerArea.x0 = 0;
	tickerArea.y0 = 0;
	tickerArea.x1 = 32;
	tickerArea.y1 = 32;

	Area logoArea;
	logoArea.x0 = 32;
	logoArea.y0 = 0;
	logoArea.x1 = 64;
	logoArea.y1 = 32;

	Area bottomArea;
	bottomArea.x0 = 0;
	bottomArea.y0 = 32;
	bottomArea.x1 = 64;
	bottomArea.y1 = 64;

	Area priceArea;
	priceArea.x0 = 0;
	priceArea.y0 = 0;
	priceArea.x1 = priceTextWidth;
	priceArea.y1 = 32;

	Area arrowArea;
	arrowArea.x0 = priceTextWidth;
	arrowArea.y0 = 0;
	arrowArea.x1 = 64 - priceTextWidth;
	arrowArea.y1 = 32;

    EXPECT_CALL(view, CreateSubMatrix(tickerArea)).WillOnce(ReturnRef(tickerView));
    EXPECT_CALL(view, CreateSubMatrix(logoArea)).WillOnce(ReturnRef(logoView));
    EXPECT_CALL(view, CreateSubMatrix(bottomArea)).WillOnce(ReturnRef(bottomView));
    EXPECT_CALL(bottomView, CreateSubMatrix(priceArea)).WillOnce(ReturnRef(priceView));
    EXPECT_CALL(bottomView, CreateSubMatrix(arrowArea)).WillOnce(ReturnRef(arrowView));
    EXPECT_CALL(bottomView, GetTextLength(StrEq("100.00"))).WillOnce(Return(priceTextWidth));
    ON_CALL(bottomView, GetHeight()).WillByDefault(Return(32));
    ON_CALL(bottomView, GetWidth()).WillByDefault(Return(64));

    EXPECT_CALL(tickerView, Write("Crwd"));
    EXPECT_CALL(logoView, Write("Picture"));
    EXPECT_CALL(priceView, Write("100.00"));
    EXPECT_CALL(arrowView, ShowPicture("./media/up_arrow.png"));

    StockAnimation animation("Crwd");

    animation.Draw(view);
}

TEST(StockSessionTests, StockSession32x32) {
    std::unique_ptr<MockStock> stock = std::make_unique<MockStock>();
    MockLedMatrixView view;
    MockLedMatrixView tickerView;
    MockLedMatrixView logoView;
    MockLedMatrixView bottomView;
    MockLedMatrixView priceView;
    MockLedMatrixView arrowView;
    auto priceTextWidth = 12;

    ON_CALL(view, GetHeight).WillByDefault(Return(32));
    ON_CALL(view, GetWidth).WillByDefault(Return(32));

    ON_CALL(*stock, Price()).WillByDefault(Return(100));
    ON_CALL(*stock, OpenPrice()).WillByDefault(Return(95));
    g_GlobalStockMocks.push(std::move(stock));

	Area tickerArea;
	tickerArea.x0 = 0;
	tickerArea.y0 = 0;
	tickerArea.x1 = 16;
	tickerArea.y1 = 16;

	Area logoArea;
	logoArea.x0 = 16;
	logoArea.y0 = 0;
	logoArea.x1 = 32;
	logoArea.y1 = 16;

	Area bottomArea;
	bottomArea.x0 = 0;
	bottomArea.y0 = 16;
	bottomArea.x1 = 32;
	bottomArea.y1 = 32;

	Area priceArea;
	priceArea.x0 = 0;
	priceArea.y0 = 0;
	priceArea.x1 = priceTextWidth;
	priceArea.y1 = 16;

	Area arrowArea;
	arrowArea.x0 = priceTextWidth;
	arrowArea.y0 = 0;
	arrowArea.x1 = 32 - priceTextWidth;
	arrowArea.y1 = 16;

    EXPECT_CALL(view, CreateSubMatrix(tickerArea)).WillOnce(ReturnRef(tickerView));
    EXPECT_CALL(view, CreateSubMatrix(logoArea)).WillOnce(ReturnRef(logoView));
    EXPECT_CALL(view, CreateSubMatrix(bottomArea)).WillOnce(ReturnRef(bottomView));
    EXPECT_CALL(bottomView, CreateSubMatrix(priceArea)).WillOnce(ReturnRef(priceView));
    EXPECT_CALL(bottomView, CreateSubMatrix(arrowArea)).WillOnce(ReturnRef(arrowView));
    EXPECT_CALL(bottomView, GetTextLength(StrEq("100.00"))).WillOnce(Return(priceTextWidth));
    ON_CALL(bottomView, GetHeight()).WillByDefault(Return(16));
    ON_CALL(bottomView, GetWidth()).WillByDefault(Return(32));

    EXPECT_CALL(tickerView, Write("Crwd"));
    EXPECT_CALL(logoView, Write("Picture"));
    EXPECT_CALL(priceView, Write("100.00"));
    EXPECT_CALL(arrowView, ShowPicture("./media/up_arrow.png"));

    StockAnimation animation("Crwd");

    animation.Draw(view);
}