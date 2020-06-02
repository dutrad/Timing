

class Logger{
public:
    static Logger& getInstance(),
    void LogMsg(const std::string& p_Text);

    Logger(const Logger&) = delete;
    void operator=(const Logger&) = delete;

private:
    Logger();
    static Logger* pInstance;
    std::thread tLog;

    void Loop();
}