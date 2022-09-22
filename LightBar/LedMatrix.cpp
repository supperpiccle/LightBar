#include <stdexcept>
#include "LedMatrix.h"
#include <regex>
#include <mutex>
#include <vector>
#include <filesystem>
#include <cassert>
#include <iostream>
#include <Magick++.h>
#include <magick/image.h>
#include <chrono>

namespace fs = std::filesystem;
using ImageVector = std::vector<Magick::Image>;

std::once_flag onceFlag;

class PictureIterator
{
public:
	PictureIterator (const std::string& ImagePath, int width, int height);
	const Magick::Image& NextImage();

private:
ImageVector m_Images;
unsigned int m_Index;
};

// Given the filename, load the image and scale to the size of the
// matrix.
// // If this is an animated image, the resutlting vector will contain multiple.
static ImageVector LoadImageAndScaleImage(const char *filename,
                                          int target_width,
                                          int target_height) {
  ImageVector result;

  ImageVector frames;
  try {
    readImages(&frames, filename);
  } catch (std::exception &e) {
    if (e.what())
      fprintf(stderr, "%s\n", e.what());
    return result;
  }

  if (frames.empty()) {
    fprintf(stderr, "No image found.");
    return result;
  }

  // Animated images have partial frames that need to be put together
  if (frames.size() > 1) {
    Magick::coalesceImages(&result, frames.begin(), frames.end());
  } else {
    result.push_back(frames[0]); // just a single still image.
  }

  for (Magick::Image &image : result) {
    image.scale(Magick::Geometry(target_width, target_height));
  }

  return result;
}

PictureIterator::PictureIterator(const std::string& ImagePath, int width, int height)
{
	m_Images = LoadImageAndScaleImage(ImagePath.c_str(), width, height);
	m_Index = m_Images.size(); // start at size so that we reset to 0 in NextImage
}

const Magick::Image& PictureIterator::NextImage()
{
	m_Index++;
	if (m_Index >= this->m_Images.size())
	{
		m_Index = 0;
	}
	return m_Images[m_Index];
}

// Copy an image to a Canvas. Note, the RGBMatrix is implementing the Canvas
// interface as well as the FrameCanvas we use in the double-buffering of the
// animted image.
void CopyImageToCanvas(int offset_x, int offset_y, const Magick::Image &image, rgb_matrix::FrameCanvas *canvas) {
  // Copy all the pixels to the canvas.
  for (size_t y = 0; y < image.rows(); ++y) {
    for (size_t x = 0; x < image.columns(); ++x) {
      const Magick::Color &c = image.pixelColor(x, y);
      if (c.alphaQuantum() < 256) {
        canvas->SetPixel(x + offset_x, y + offset_y,
                         ScaleQuantumToChar(c.redQuantum()),
                         ScaleQuantumToChar(c.greenQuantum()),
                         ScaleQuantumToChar(c.blueQuantum()));
      }
    }
  }
}

LedMatrixView::LedMatrixView(Area MatrixArea, rgb_matrix::FrameCanvas **Offscreen_canvas, std::shared_ptr<rgb_matrix::Font> Font)
{
	m_MyArea = MatrixArea;
	m_Offscreen_canvas = Offscreen_canvas;
	m_Font = Font;

	std::lock_guard<std::mutex> lock(m_RedrawMutex);
	m_UpdateCanvasFunction = [this]()
	{
		this->SplashColor(RGB{0, 0, 0});
	};
}

void LedMatrixView::UpdateCanvas()
{
	std::lock_guard<std::mutex> lock(m_RedrawMutex);
	m_UpdateCanvasFunction();
}


void LedMatrixView::ApplyCustomBitmap(std::function<void(RGB, unsigned int x, unsigned int y)> callback)
{
	return;
}

ILedMatrixView& LedMatrixView::CreateSubMatrix(Area area)
{
	std::lock_guard<std::mutex> lock(m_RedrawMutex);

	Area nestedArea;
	nestedArea.x0 = m_MyArea.x0 + area.x0;
	nestedArea.x1 = m_MyArea.x0 + area.x1;
	nestedArea.y0 = m_MyArea.y0 + area.y0;
	nestedArea.y1 = m_MyArea.y0 + area.y1;

	m_NestedViews.emplace_back(nestedArea, m_Offscreen_canvas, m_Font);
	m_UpdateCanvasFunction = [this]()
	{
		for (auto& subView : m_NestedViews)
		{
			subView.UpdateCanvas();
		}
	};
	return m_NestedViews.back();
}

void LedMatrixView::Shift(int Up, int Right)
{
	m_MyArea.x0 += Right;
	m_MyArea.x1 += Right;
	m_MyArea.y0 -= Up;
	m_MyArea.y1 -= Up;
	for (auto& nested_view : m_NestedViews)
	{
		nested_view.Shift(Up, Right);
	}
}

Area LedMatrixView::GetAbsoluteArea()
{
	return m_MyArea;
}

bool LedMatrixView::Write(std::string text)
{
	auto font_height = m_Font->baseline();
	if (m_MyArea.y0 + font_height > m_MyArea.y1)
	{
		std::cout << "Cannot fit text: \"" << text << "\" within y coords of " << m_MyArea.y0 << " and " << m_MyArea.y1 << std::endl;
		return false;
	}

	// Clip the string if we need to.
	assert(m_MyArea.x0 < m_MyArea.x1);
	auto x_diff = m_MyArea.x1 - m_MyArea.x0;

	auto copy = text;
	while (GetTextLength(text) > x_diff)
	{
		text = text.substr(0, text.length() - 1);
	}

	std::lock_guard<std::mutex> lock(m_RedrawMutex);
	m_UpdateCanvasFunction = [this, text]()
	{
		int x = m_MyArea.x0;
		int y = m_MyArea.y0;

 	 	rgb_matrix::Color color(255, 255, 0);
		int letter_spacing = 0;

 	   // length = holds how many pixels our text takes up
 	   auto length = rgb_matrix::DrawText(*m_Offscreen_canvas, *m_Font,
 	                                 x, y + m_Font->baseline(),
 	                                 color, nullptr,
 	                                 text.c_str(), letter_spacing);
	};
}

unsigned int LedMatrixView::GetTextLength(std::string text)
{
	unsigned int count = 0;
	for (auto c : text)
	{
		count += m_Font->CharacterWidth(c);
	}
	return count;
}
void LedMatrixView::ShowPicture(std::string PicturePath)
{
	std::lock_guard<std::mutex> lock(m_RedrawMutex);
	auto width = m_MyArea.x1 - m_MyArea.x0;
	auto height = m_MyArea.y1 - m_MyArea.y0;
	auto images = LoadImageAndScaleImage(PicturePath.c_str(), width, height);
	PictureIterator picIterator(PicturePath, width, height);
	m_UpdateCanvasFunction = [picIterator, this]() mutable
	{
		CopyImageToCanvas(m_MyArea.x0, m_MyArea.y0, picIterator.NextImage(), *m_Offscreen_canvas);
	};
}
void LedMatrixView::SplashColor(RGB Color)
{
	(*m_Offscreen_canvas)->Fill(Color.Red, Color.Green, Color.Blue);
}

void LedMatrixView::SetPixal(unsigned int x, unsigned int y, RGB color)
{

}

unsigned int LedMatrixView::GetHeight()
{
	return m_MyArea.y1 - m_MyArea.y0;
}
unsigned int LedMatrixView::GetWidth()
{
	return m_MyArea.x1 - m_MyArea.x0;
}

void LedMatrixView::ClearSubViews()
{
	std::lock_guard<std::mutex> lock(m_RedrawMutex);
	m_NestedViews.clear();
	m_UpdateCanvasFunction = []()
	{
	};
}

//-------------------------------------------------------------------------

LedMatrix::LedMatrix()
{
  	rgb_matrix::RGBMatrix::Options matrix_options;
  	rgb_matrix::RuntimeOptions runtime_opt;

	matrix_options.disable_hardware_pulsing = true;
	matrix_options.cols = 64;
	matrix_options.rows = 64;
	matrix_options.hardware_mapping = "adafruit-hat";

	m_Canvas = std::shared_ptr<rgb_matrix::RGBMatrix>(rgb_matrix::CreateMatrixFromOptions(matrix_options, runtime_opt));
	if (m_Canvas == nullptr)
	{
		throw std::runtime_error("Failed to allocate m_Canvas");
	}

  	// Create a new canvas to be used with led_matrix_swap_on_vsync
  	m_Offscreen_canvas = m_Canvas->CreateFrameCanvas();
	Area area;
	area.x0 = 0;
	area.y0 = 0;
	area.x1 = 64;
	area.y1 = 64;

    std::call_once( onceFlag, [ ]{ Magick::InitializeMagick(nullptr); });

	auto fonts = GetFontFiles();
	m_FontFilePath = fonts[0];
	m_Font = std::make_shared<rgb_matrix::Font>();
  	if (!m_Font->LoadFont(m_FontFilePath.c_str())) {
  	  fprintf(stderr, "Couldn't load font '%s'\n", m_FontFilePath.c_str());
		throw std::runtime_error("Failed to load font");
  	}

	m_View = std::shared_ptr<LedMatrixView>(new LedMatrixView(area, &m_Offscreen_canvas, m_Font));
	auto *t = new std::thread(&LedMatrix::WorkerThread, this);
    m_AsyncUpdateThread = std::unique_ptr<std::thread>(t);
}

LedMatrix::~LedMatrix()
{
	m_Rundown = true;
	if(m_AsyncUpdateThread->joinable())
	{
		m_AsyncUpdateThread->join();
	}
}

ILedMatrixView* LedMatrix::CreateView()
{
	return m_View.get();
}
void LedMatrix::Draw()
{
	std::lock_guard<std::mutex> lock(m_RedrawMutex);
	m_View->UpdateCanvas();
    // Swap the offscreen_canvas with canvas on vsync, avoids flickering
    m_Offscreen_canvas = m_Canvas->SwapOnVSync(m_Offscreen_canvas);

	// Clear the last canvas here.
    m_Offscreen_canvas->Fill(0, 0, 0);
}
void LedMatrix::Clear()
{

}
void LedMatrix::Redraw()
{

}

void LedMatrix::WorkerThread()
{
	//while(!m_Rundown)
	//{
		//m_View->UpdateCanvas();
		//Draw();
		//std::this_thread::sleep_for(std::chrono::milliseconds(100));
	//}
}

std::vector<std::string> LedMatrix::GetFontFiles()
{
	std::regex font_regex = std::regex("[0-9]*x[0-9]*\\.bdf");
	std::string font_path = "/home/pi/LightBar/LightBar/third-party/rpi-rgb-led-matrix/fonts/";
	std::vector<std::string> fonts;
	for (const auto& entry : std::filesystem::directory_iterator(font_path))
	{
		std::string path = entry.path();
		std::string filename = path.substr(path.rfind('/') + 1);
		if (std::regex_match(filename, font_regex))
		{
			fonts.push_back(entry.path());
		}
	}
	return fonts;
}