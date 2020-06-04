#include <string>
#include <queue>
#include <thread>
#include <mutex>
#include <iostream> 

class Logger{
public:
    static Logger* getInstance();
    void LogMsg(const std::string& p_Text);

    Logger(const Logger&) = delete;
    void operator=(const Logger&) = delete;

private:
    Logger();
    ~Logger();
    static Logger* m_Instance;
    
    std::thread m_Thread;
    void mainLoop();
    bool m_Exit;

    std::mutex qMutex;
    static std::queue<std::string> m_Queue;

};