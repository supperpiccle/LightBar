#pragma once
#include <chrono>
#include <string>
#include <ILedMatrix.h>
#include <Magick++.h>
#include <magick/image.h>
#include <map>
#include <vector>
#include <mutex>

using ImageVector = std::vector<Magick::Image>;

enum class StockUpdateResult
{
    Success,
    Error
};

namespace Details
{
    class InternetPictureCache
    {
    public:

        InternetPictureCache(const std::string& ScratchDirectory);
        std::string Get(std::string URL);

    private:

        std::string WriteToRandomFile(const std::string& Data);

        std::map<std::string, std::string> m_UrlToLocalPath;
        std::string m_ScratchDirectory;
        std::mutex m_Mut;
        unsigned int m_Num = 0;
    };

    extern std::unique_ptr<InternetPictureCache> g_StockLogoCache;
}

class IPicture
{
public:
    virtual std::string GetPath() = 0;
    virtual void ApplyImage(ILedMatrixView& View) = 0;
};

class IStock
{
public:
    virtual std::string Ticker() = 0;
    virtual double Price() = 0;
    virtual unsigned int Volume() = 0;
    virtual double OpenPrice() = 0;
    virtual double ClosePrice() = 0;
    virtual double ChangeToday() = 0;
    virtual IPicture& Logo() = 0;
    virtual StockUpdateResult Update() = 0;
};

std::unique_ptr<IStock> CreateStock(std::string Ticker);

class Stock : public IStock
{
public:
    Stock(const std::string& Ticker);

    virtual std::string Ticker() override;
    virtual double Price() override;
    virtual unsigned int Volume() override;
    virtual double OpenPrice() override;
    virtual double ClosePrice() override;
    virtual double ChangeToday() override;
    virtual IPicture& Logo() override;
    virtual StockUpdateResult Update() override;

private:

    std::string GetApiResponse();

    double m_CurrentPrice = 0;
    double m_OpenPrice = 0;
    double m_ClosePrice = 0;
    double m_HighPrice = 0;
    double m_LowPrice = 0;
    unsigned int m_Volume = 0;

    std::string m_Ticker;
    std::string m_ApiKey;
};

class Picture : public IPicture
{
public:

    Picture(std::string path);

    virtual std::string GetPath() override;
    virtual void ApplyImage(ILedMatrixView& View) override;

private:
    std::string m_Path;
    ImageVector m_Images;
    Magick::Image* m_CurrentImage;
};

class YahooStock : public IStock
{
public:
    YahooStock(const std::string& Ticker);

    virtual std::string Ticker() override;
    virtual double Price() override;
    virtual unsigned int Volume() override;
    virtual double OpenPrice() override;
    virtual double ClosePrice() override;
    virtual double ChangeToday() override;
    virtual IPicture& Logo() override;
    virtual StockUpdateResult Update() override;

private:

    double m_CurrentPrice = 0;
    double m_OpenPrice = 0;
    double m_ClosePrice = 0;
    double m_HighPrice = 0;
    double m_LowPrice = 0;
    unsigned int m_Volume = 0;

    std::string m_Ticker;
    std::shared_ptr<Picture> m_Logo;
};
