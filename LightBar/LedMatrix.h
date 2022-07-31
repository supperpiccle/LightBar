#include <string>
#include <list>
#include <functional>
#include <memory>
#include <vector>
#include <deque>
#include <mutex>
#include <thread>

#include "led-matrix.h"
#include "graphics.h"

/*

 x0, y0                   x1,y0




 x0, y1                   x1,y1

*/
struct Area
{
	unsigned int x0;
	unsigned int y0;
	unsigned int x1;
	unsigned int y1;
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

class LedMatrixView
{
public:
	LedMatrixView(Area MatrixArea, rgb_matrix::FrameCanvas **Offscreen_canvas);

	LedMatrixView& CreateSubMatrix(Area area);
	bool Write(std::string text);
	// void ShiftLeft();
	// void ShiftRight();
	unsigned int GetTextLength(std::string text);
	void ShowPicture(std::string PicturePath);
	LedMatrixView& MultiDisplayWrite();
	void ApplyCustomBitmap(std::function<void(RGB, unsigned int x, unsigned int y)> callback);
	void SplashColor(RGB Color);

	unsigned int GetHeight();
	unsigned int GetWidth();

	void UpdateCanvas();
	void ClearSubViews();

private:

	std::vector<std::string> GetFontFiles();
	unsigned int GetStringWidth(std::string text);

	std::shared_ptr<rgb_matrix::RGBMatrix> m_Canvas;
  	rgb_matrix::FrameCanvas **m_Offscreen_canvas;
  	std::shared_ptr<rgb_matrix::Font> m_Font;

	Area m_OriginalArea;
	Area m_MyArea;
	std::string m_FontFilePath;
	std::deque<LedMatrixView> m_NestedViews;

	std::function<void(void)> m_UpdateCanvasFunction;
	std::mutex m_RedrawMutex;
};

class LedMatrix
{
public:
	LedMatrix();
	~LedMatrix();
	LedMatrixView* CreateView();
	void Draw();
	void Clear();
	void Redraw();

private:

	void WorkerThread();

	std::shared_ptr<rgb_matrix::RGBMatrix> m_Canvas;
	std::shared_ptr<LedMatrixView> m_View;
  	rgb_matrix::FrameCanvas *m_Offscreen_canvas;
	std::mutex m_RedrawMutex;
	bool m_Rundown = false;

	std::unique_ptr<std::thread> m_AsyncUpdateThread;
};
