#include "Logger.hpp"

Logger& Logger::getInstance(){
    if(pInstance == 0){
        Lock
        if(pInstance == 0){
            pInstance = new Logger();
        }
    }
    return instance;
}

void Logger::LogMsg(const std::string& p_Text){
    mtx.lock();
    m_Queue.push(p_Text)
    mtx.unlock();
}

Logger::Logger(){
    tLog.start
}

Logger::~Logger(){
    m_Exit = true;
}

void Logger::mainLoop(){
    while (!m_Exit)
    {
        /* code */
    }

    while (!m_Queue.empty())
    {
        //Save to file
    }    
}

