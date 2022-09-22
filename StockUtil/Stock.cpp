#include <iostream>
#include <regex>

#include "Stock.h"
#include <curl/curl.h>
#include <fstream>
#include <filesystem>

#define RAPIDJSON_HAS_STDSTRING 1
#include <rapidjson/rapidjson.h>
#include <rapidjson/document.h>

namespace Details
{
    std::unique_ptr<InternetPictureCache> g_StockLogoCache;
}

Stock::Stock(const std::string& Ticker)
    : m_Ticker(Ticker)
{
    const char* apiKeyName = "ALPHAVANTAGEKEY";
    char* apiKey = std::getenv(apiKeyName);
    if (apiKey == nullptr)
    {
        throw std::string("The ") + std::string(apiKeyName) + std::string(" environment variable not found!");
    }
    m_ApiKey = apiKeyName;
    Update();
}

std::string Stock::Ticker()
{
    return m_Ticker;
}

double Stock::Price()
{
    return m_CurrentPrice;
}

unsigned int Stock::Volume()
{
    return m_Volume;
}

double Stock::OpenPrice()
{
    return m_OpenPrice;
}

double Stock::ClosePrice()
{
    return m_ClosePrice;
}

double Stock::ChangeToday()
{
    return m_CurrentPrice - m_OpenPrice;
}

IPicture& Stock::Logo()
{
    throw std::runtime_error(std::string("Logo() not implemented for Stock."));
}

static size_t write_function(void *data, size_t size, size_t nmemb, void *userp)
{
    size_t realsize = size * nmemb;

    std::string* str = (std::string*) userp;

    for (int i = 0; i < realsize; i++)
    {
        str->push_back(((char*)data)[i]);
    }

    return realsize;
}

std::string Stock::GetApiResponse()
{
    std::string url =
        std::string("https://www.alphavantage.co/query?") +
        std::string("function=GLOBAL_QUOTE") +
        std::string("&interval=5min") +
        std::string("&apikey=") + m_ApiKey +
        std::string("&symbol=") + m_Ticker;

    CURL* curl = curl_easy_init();
    std::string responseBuffer;


    if (curl) {


        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_HTTP_VERSION, CURL_HTTP_VERSION_1_0);
        curl_easy_setopt(curl, CURLOPT_HTTPGET, 1L);
        curl_easy_setopt(curl, CURLOPT_FORBID_REUSE, 1L); 

        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, &write_function);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &responseBuffer);
        //curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);

        // Perform the request
        CURLcode res = curl_easy_perform(curl);

        // Cleanup
        curl_easy_cleanup(curl);
    }

    return responseBuffer;
}

StockUpdateResult Stock::Update()
{
    try
    {
        auto serverResponse = GetApiResponse();

        rapidjson::Document doc;
        doc.Parse(serverResponse);

        try
        {
            if (!doc.HasMember("Global Quote"))
            {
                return StockUpdateResult::Error;
            }
            const auto& globalQuote = doc["Global Quote"].GetObject();

            m_OpenPrice = atof(globalQuote["02. open"].GetString());
            m_HighPrice = atof(globalQuote["03. high"].GetString());
            m_LowPrice = atof(globalQuote["04. low"].GetString());
            m_CurrentPrice = atof(globalQuote["05. price"].GetString());
            m_Volume = atoi(globalQuote["06. volume"].GetString());
            //atof(globalQuote["07. latest trading day"].GetString());
            m_ClosePrice = atof(globalQuote["08. previous close"].GetString());
            //atof(globalQuote["09. change"].GetString());
            //atof(globalQuote["10. change percent"].GetString());
            return StockUpdateResult::Success;
        }
        catch(...)
        {
            return StockUpdateResult::Error;
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return StockUpdateResult::Error;
    }
}

YahooStock::YahooStock(const std::string& Ticker)
    : m_Ticker(Ticker)
{
    Update();
}

std::string YahooStock::Ticker()
{
    return m_Ticker;
}

double YahooStock::Price()
{
    return m_CurrentPrice;
}

unsigned int YahooStock::Volume()
{
    return m_Volume;
}

double YahooStock::OpenPrice()
{
    return m_OpenPrice;
}

double YahooStock::ClosePrice()
{
    return m_ClosePrice;
}

double YahooStock::ChangeToday()
{
    return m_CurrentPrice - m_OpenPrice;
}

IPicture& YahooStock::Logo()
{
    return *m_Logo;
}

StockUpdateResult YahooStock::Update()
{
    try
    {
        std::string command = std::string("python3 ./stock_data_getter.py ") + m_Ticker;
        std::stringstream output;

        char buf[1024];
        FILE* filePipe = popen(command.c_str(), "r");

        while(fgets(buf, sizeof(buf), filePipe) != NULL)
        {
            output << buf;
        }

        rapidjson::Document doc;
        doc.Parse(output.str());

        try
        {
            if (!doc.HasMember("zip"))
            {
                return StockUpdateResult::Error;
            }

            m_OpenPrice = doc["open"].GetDouble();
            m_HighPrice = doc["dayHigh"].GetDouble();
            m_LowPrice = doc["dayLow"].GetDouble();
            m_CurrentPrice = doc["currentPrice"].GetDouble();
            m_Volume = doc["volume"].GetDouble();
            m_ClosePrice = doc["previousClose"].GetDouble();

            // Now get the logo picture.
            auto logoFilePath = Details::g_StockLogoCache->Get(doc["logo_url"].GetString());
            m_Logo = std::make_shared<Picture>(logoFilePath);

            return StockUpdateResult::Success;
        }
        catch(...)
        {
            return StockUpdateResult::Error;
        }


    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return StockUpdateResult::Error;
    }
}



Picture::Picture(std::string path)
{
    ImageVector result;
    ImageVector frames;

    try
    {
      readImages(&frames, path);
    }
    catch (std::exception &e)
    {
      if (e.what())
      {
        std::cout << e.what() << std::endl;
      }
    }

    if (frames.empty())
    {
        std::cout << "No images in " << path << std::endl;
        return;
    }

    // Animated images have partial frames that need to be put together
    if (frames.size() > 1)
    {
        Magick::coalesceImages(&result, frames.begin(), frames.end());
    }
    else
    {
        result.push_back(frames[0]); // just a single still image.
    }
}

std::string Picture::GetPath()
{
    return m_Path;
}
void Picture::ApplyImage(ILedMatrixView& View)
{
    for (Magick::Image &image : m_Images)
    {
        image.scale(Magick::Geometry(View.GetWidth(), View.GetHeight()));
    }

    Magick::Image &image = m_Images[0];

    // Copy all the pixels to the canvas.
    for (size_t y = 0; y < image.rows(); ++y)
    {
        for (size_t x = 0; x < image.columns(); ++x)
        {
            const Magick::Color &c = image.pixelColor(x, y);
            if (c.alphaQuantum() < 256)
            {
                RGB color;
                color.Blue = ScaleQuantumToChar(c.blueQuantum());
                color.Green = ScaleQuantumToChar(c.greenQuantum());
                color.Red = ScaleQuantumToChar(c.redQuantum());
                View.SetPixal(x, y, color);
            }
        }
    }
}

Details::InternetPictureCache::InternetPictureCache(const std::string& ScratchDirectory)
{
    std::string cacheName = "StockLogoCache";
    std::filesystem::path cacheDir = std::filesystem::path(ScratchDirectory) / std::filesystem::path(cacheName);
    m_ScratchDirectory = cacheDir;

    if (std::filesystem::exists(cacheDir))
    {
        std::filesystem::remove_all(cacheDir);
    }
    std::filesystem::create_directory(cacheDir);
}

std::string Details::InternetPictureCache::Get(std::string URL)
{
    std::lock_guard<std::mutex> lck(m_Mut);

    // Look at our cache first.
    auto it = m_UrlToLocalPath.find(URL);
    if (it != m_UrlToLocalPath.end())
    {
        return it->second;
    }

    //
    // Download the file to our scratch directory.
    //
    CURL* curl = curl_easy_init();
    std::string responseBuffer;

    if (curl)
    {
        curl_easy_setopt(curl, CURLOPT_URL, URL.c_str());
        curl_easy_setopt(curl, CURLOPT_HTTP_VERSION, CURL_HTTP_VERSION_1_0);
        curl_easy_setopt(curl, CURLOPT_HTTPGET, 1L);
        curl_easy_setopt(curl, CURLOPT_FORBID_REUSE, 1L); 

        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, &write_function);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &responseBuffer);
        //curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);

        // Perform the request
        CURLcode res = curl_easy_perform(curl);

        // Cleanup
        curl_easy_cleanup(curl);
    }

    // Using the url as the key, write to a file with a random filename.
    auto filename = WriteToRandomFile(responseBuffer);

    m_UrlToLocalPath[URL] = filename;
    return filename;
}

std::string Details::InternetPictureCache::WriteToRandomFile(const std::string& Data)
{
    std::string filename = std::filesystem::path(m_ScratchDirectory) / std::filesystem::path(std::to_string(m_Num++));
    std::ofstream f(filename);
    f << Data;

    return filename;
}