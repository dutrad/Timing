#include <string>
#include <chrono>
#include <iostream>
#include "Logger.h"

using namespace std;

class Timer
{
public:
    Timer(const string &functionName):m_functionName(functionName)
    {
        m_startingPoint = chrono::high_resolution_clock::now();
    };

    ~Timer()
    {
        auto endPoint = chrono::high_resolution_clock::now();

        std::chrono::duration<double, std::micro> duration = endPoint - m_startingPoint;

        Logger::getInstance()->LogMsg(m_functionName + ":" + std::to_string(duration.count()) + "\xC2\xB5s \n");
    };

private:
string m_functionName;
chrono::time_point<chrono::high_resolution_clock> m_startingPoint;

};