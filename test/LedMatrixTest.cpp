#include <iostream>
#include "LedMatrix.h"

#include <getopt.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <map>
#include <rapidjson/rapidjson.h>
#include <rapidjson/document.h>
#include <fstream>
#include <sstream>
#include <filesystem>

void CommandWrite(ILedMatrixView* View, const std::string& Args);
void CommandPicture(ILedMatrixView* View, const std::string& Args);
void CommandShiftx(ILedMatrixView* View, const std::string& Args);
void CommandShifty(ILedMatrixView* View, const std::string& Args);
void CommandResetPostion(ILedMatrixView* View, const std::string& Args);
void MultiCommand(ILedMatrixView* View, const std::string& Args);
void MultiCommandFile(ILedMatrixView* View, const std::string& Args);

LedMatrix matrix;
ILedMatrixView* view;
//std::vector<std::unique_ptr<LedMatrixView>> subViews;
std::map<std::string, void(*)(ILedMatrixView*, const std::string&)> g_CommandMap = {
    {"write", CommandWrite},
    {"picture", CommandPicture},
    {"shiftx", CommandShiftx},
    {"shifty", CommandShifty},
    {"resetposition", CommandResetPostion},
    {"command", MultiCommandFile}
};


int g_xShifted = 0;
int g_yShifted = 0;

void CommandWrite(ILedMatrixView* View, const std::string& Args)
{
    view->ClearSubViews();
    View->Write(Args);
}

void CommandPicture(ILedMatrixView* View, const std::string& Args)
{
    view->ClearSubViews();
    View->ShowPicture(Args);
}

void CommandShiftx(ILedMatrixView* View, const std::string& Args)
{
    int x = atoi(Args.c_str());
    g_xShifted += x;
    View->Shift(0, x);
}
void CommandShifty(ILedMatrixView* View, const std::string& Args)
{
    int y = atoi(Args.c_str());
    g_yShifted += y;
    View->Shift(y, 0);
}
void CommandResetPostion(ILedMatrixView* View, const std::string& Args)
{
    View->Shift(-g_yShifted, -g_xShifted);
    g_xShifted = 0;
    g_yShifted = 0;
}

void MultiCommand(ILedMatrixView* View, const std::string& Args)
{
    view->ClearSubViews();
    rapidjson::Document doc;
    doc.Parse(Args.c_str());

    for (const auto& entry : doc.GetArray())
    {
        Area area;
        area.x0 = entry["LeftCorner"].GetArray()[0].GetInt();
        area.x1 = entry["RightCorner"].GetArray()[0].GetInt();
        area.y0 = entry["LeftCorner"].GetArray()[1].GetInt();
        area.y1 = entry["RightCorner"].GetArray()[1].GetInt();

        std::string operation = entry["Operation"].GetString();

        std::string command = operation.substr(0, operation.find(' '));
        std::string args = operation.substr(operation.find(' ') + 1);
        g_CommandMap[command](&View->CreateSubMatrix(area), args);
    }
}

void MultiCommandFile(ILedMatrixView* View, const std::string& Args)
{
    view->ClearSubViews();
    if (!std::filesystem::exists(Args))
    {
        std::cout << "File " << Args << " does not exist!" << std::endl;
        return;
    }
    std::ifstream t(Args);
    std::stringstream buffer;
    buffer << t.rdbuf();

    MultiCommand(View, buffer.str());
}

int main(int argc, char** argv)
{
    std::string text = "Bottom Text";
    std::cout << "Welcome to Led Matrix Test Utility" << std::endl;

    std::cout << "Writing the static word \"" << text << "\"" << std::endl;

    view = matrix.CreateView();
    Area tempArea;
    tempArea.x0 = 0;
    tempArea.y0 = 0;
    tempArea.x1 = 128;
    tempArea.y1 = 52;
    view->SetAbsoluteArea(tempArea);

    view->Write(text);
    matrix.Draw();

    int delay_speed_usec = 10000000;
    while(true)
    {
        std::string user_command;
        std::cout << "Enter command: ";

        std::getline(std::cin, user_command);


        std::string command = user_command.substr(0, user_command.find(' '));
        std::string args = user_command.substr(user_command.find(' ') + 1);
        if (command == std::string("exit"))
        {
            break;
        }
        //TODO Fix seg fault here when command not found
        g_CommandMap[command](view, args);
        matrix.Draw();
    }
}