#pragma once
#include <string>
#include <functional>
#include <memory>

/*

 x0, y0                   x1,y0




 x0, y1                   x1,y1

*/
struct Area
{
	int x0;
	int y0;
	int x1;
	int y1;

	Area operator+(const Area& rhs)
	{
		Area ret;
		ret.x0 = x0 + rhs.x0;
		ret.x1 = x1 + rhs.x1;
		ret.y0 = y0 + rhs.y0;
		ret.y1 = y1 + rhs.y1;

		return ret;
	}
};

enum class Positioning
{
	Center,
	Right,
	Left
};

struct RGB
{
	unsigned short Red;
	unsigned short Green;
	unsigned short Blue;
};

class ILedMatrixView
{
public:

    ILedMatrixView() = default;
    ~ILedMatrixView() = default;

	virtual ILedMatrixView& CreateSubMatrix(Area area) = 0;
	virtual bool Write(std::string text) = 0;
	virtual unsigned int GetTextLength(std::string text) = 0;
	virtual void ShowPicture(std::string PicturePath) = 0;
	virtual void ApplyCustomBitmap(std::function<void(RGB, unsigned int x, unsigned int y)> callback) = 0;
	virtual void SetPixal(unsigned int x, unsigned int y, RGB color) = 0;
	virtual void SplashColor(RGB Color) = 0;
	virtual void Shift(int Up, int Right) = 0;
	virtual Area GetAbsoluteArea() = 0;
	virtual void SetAbsoluteArea(Area area) = 0;

	virtual unsigned int GetHeight() = 0;
	virtual unsigned int GetWidth() = 0;

	virtual void UpdateCanvas() = 0;
	virtual void ClearSubViews() = 0;
};

class ILedMatrix
{
public:
	ILedMatrix() = default;
	~ILedMatrix() = default;

	virtual ILedMatrixView* CreateView() = 0;
	virtual void Draw() = 0 ;
	virtual void Clear() = 0 ;
	virtual void Redraw() = 0 ;
};
