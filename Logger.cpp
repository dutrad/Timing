#include "Logger.hpp"

Logger::getInstance(){
    if(pInstance == 0){
        Lock
        if(pInstance == 0){
            pInstance = new Logger();
        }
    }
    return instance;
}

Logger::LogMsg(const std::string& p_Text){

}

Logger::Logger(){
    tLog.start
}

