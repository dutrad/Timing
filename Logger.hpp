#include <string>
#include <queue>
#include <thread>
#include <mutex>
#include <iostream> 

class Logger{
public:
    static Logger& getInstance(),
    void LogMsg(const std::string& p_Text);

    Logger(const Logger&) = delete;
    void operator=(const Logger&) = delete;

private:
    Logger();
    ~Logger();
    static Logger* pInstance;
    
    std::thread tLog;
    void mainLoop();
    static bool m_Exit = false;

    std::mutex mtx;
    static std:queue<std::string> m_Queue;

}