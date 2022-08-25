#include <iostream>
#include <regex>

#include "Stock.h"
#include <curl/curl.h>

#define RAPIDJSON_HAS_STDSTRING 1
#include <rapidjson/rapidjson.h>
#include <rapidjson/document.h>


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

static size_t write_function(void *data, size_t size, size_t nmemb, void *userp)
{
    size_t realsize = size * nmemb;

    std::string* str = (std::string*) userp;

    for (int i = 0; i < realsize; i++)
    {
        str->push_back(((char*)data)[i]);
    }

    return realsize;
};

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
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return StockUpdateResult::Error;
    }
    

}