#include "ILedMatrix.h"
#include <memory>
#include <vector>
#include <deque>
#include <mutex>
#include <thread>

#include "led-matrix.h"
#include "graphics.h"

class LedMatrixView : public ILedMatrixView
{
public:
	LedMatrixView(Area MatrixArea, rgb_matrix::FrameCanvas **Offscreen_canvas, std::shared_ptr<rgb_matrix::Font> Font);

	ILedMatrixView& CreateSubMatrix(Area area);
	bool Write(std::string text) override;
	unsigned int GetTextLength(std::string text) override;
	void ShowPicture(std::string PicturePath) override;
	void ApplyCustomBitmap(std::function<void(RGB, unsigned int x, unsigned int y)> callback) override;
	void SplashColor(RGB Color) override;
	void Shift(int Up, int Right) override;
	Area GetAbsoluteArea() override;

	unsigned int GetHeight() override;
	unsigned int GetWidth() override;

	void UpdateCanvas() override;
	void ClearSubViews() override;

private:


	std::shared_ptr<rgb_matrix::RGBMatrix> m_Canvas;
  	rgb_matrix::FrameCanvas **m_Offscreen_canvas;
  	std::shared_ptr<rgb_matrix::Font> m_Font;

	Area m_OriginalArea;
	Area m_MyArea;
	std::deque<LedMatrixView> m_NestedViews;

	std::function<void(void)> m_UpdateCanvasFunction;
	std::mutex m_RedrawMutex;
};

class LedMatrix : public ILedMatrix
{
public:
	LedMatrix();
	~LedMatrix();

	ILedMatrixView* CreateView() override;
	void Draw() override;
	void Clear() override;
	void Redraw() override;

private:

	void WorkerThread();

	std::shared_ptr<rgb_matrix::RGBMatrix> m_Canvas;
	std::shared_ptr<LedMatrixView> m_View;
  	rgb_matrix::FrameCanvas *m_Offscreen_canvas;
	std::mutex m_RedrawMutex;
	bool m_Rundown = false;
	std::string m_FontFilePath;

	std::unique_ptr<std::thread> m_AsyncUpdateThread;
  	std::shared_ptr<rgb_matrix::Font> m_Font;

	std::vector<std::string> GetFontFiles();
};
