#pragma once
#include <string>
#include <vector>
#include "ILedMatrix.h"

class SessionManager
{
public:
    SessionManager();

    void Run(ILedMatrix& Matrix);
private:
    std::vector<std::string> m_Tickers;
};
