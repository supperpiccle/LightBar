#include <gmock/gmock.h>
#include <ILedMatrix.h>

class MockLedMatrixView : public ILedMatrixView
{
    public:

    MockLedMatrixView() = default;
    ~MockLedMatrixView() = default;

	MOCK_METHOD(ILedMatrixView&, CreateSubMatrix, (Area area), (override));
	MOCK_METHOD(bool, Write, (std::string text), (override));
	MOCK_METHOD(unsigned int, GetTextLength, (std::string text), (override));
	MOCK_METHOD(void, ShowPicture, (std::string PicturePath), (override));
	MOCK_METHOD(void, ApplyCustomBitmap, (std::function<void(RGB, unsigned int x, unsigned int y)> callback), (override));
	MOCK_METHOD(void, SetPixal, (unsigned int x, unsigned int y, RGB color), (override));
	MOCK_METHOD(void, SplashColor, (RGB Color), (override));
	MOCK_METHOD(void, Shift, (int Up, int Right), (override));
	MOCK_METHOD(Area, GetAbsoluteArea, (), (override));
	MOCK_METHOD(void, SetAbsoluteArea, (Area area), (override));

	MOCK_METHOD(unsigned int, GetHeight, (), (override));
	MOCK_METHOD(unsigned int, GetWidth, (), (override));

	MOCK_METHOD(void, UpdateCanvas, (), (override));
	MOCK_METHOD(void, ClearSubViews, (), (override));
};