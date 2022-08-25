#pragma once
#include <string>
#include "ILedMatrix.h"

class SessionManager
{
public:
    SessionManager();

    void Run(ILedMatrix& Matrix);
private:
    std::string m_Tickers;
};
