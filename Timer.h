#include <string>
#include <chrono>
#include <iostream>

class Timer
{
public:
    Timer(const std::string &functionName):m_functionName(functionName)
    {
        m_startingPoint = std::chrono::high_resolution_clock::now();
    };

    ~Timer()
    {
        auto endPoint = std::chrono::high_resolution_clock::now();
        auto end = std::chrono::time_point_cast<std::chrono::microseconds>(endPoint).time_since_epoch();
        auto start = std::chrono::time_point_cast<std::chrono::microseconds>(m_startingPoint).time_since_epoch();
        
        auto duration = end - start;

        std::cout << duration;
    };

private:
std::string m_functionName;
std::chrono::time_point<std::chrono::high_resolution_clock> m_startingPoint;

};