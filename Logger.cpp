#include "Logger.h"

#include <chrono>
#include <thread>
#include <fstream>

Logger* Logger::getInstance(){
    if(m_Instance == 0){
        m_Instance = new Logger();
    }        
    return m_Instance;
}

void Logger::LogMsg(const std::string& p_Text){
    qMutex.lock();
    m_Queue.push(p_Text);
    qMutex.unlock();
}

Logger::Logger() : m_Exit(false), m_Thread(&Logger::mainLoop, this){}

Logger::~Logger(){
    m_Exit = true;
    m_Thread.join();
}

void Logger::mainLoop(){
    std::ofstream file("output.txt");
    std::string msg;

    while (!m_Exit)
    {
        while (!m_Queue.empty())
        {
            msg = m_Queue.front();
            m_Queue.pop();
            file << msg;
        }    
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }

    while (!m_Queue.empty())
    {
        //Save to file
    }
    file.close();    
}

