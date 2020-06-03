#include "Logger.hpp"

Logger* Logger::getInstance(){
    if(m_Instance == 0){
        pMutex.lock();
        if(m_Instance == 0){
            m_Instance = new Logger();
        }
    }
    pMutex.unlock();
    return m_Instance;
}

void Logger::LogMsg(const std::string& p_Text){
    qMutex.lock();
    m_Queue.push(p_Text);
    qMutex.unlock();
}

Logger::Logger() : m_Exit(false){
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

