// https://www.youtube.com/watch?v=3dHBFBw13E0&list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb&index=20
#include <iostream>
using namespace std;

class Log {
public:
    // use enum so that level can only be set to what is mentioned inside the enum Level and not any random value.
    enum Level {
        LogLevelError, LogLevelWarn, LogLevelInfo        // LogLevelError=0, LogLevelWarn=1, LogLevelInfo=2
    };
    // const int LogLevelError = 0;
    // const int LogLevelWarn = 1;
    // const int LogLevelInfo = 2;
private:
    Level m_LogLevel = LogLevelInfo;         // m_ denotes that the member key is private
public:
    void setLevel(Level level) {
        m_LogLevel = level;
    }

    void Error(const char* message) {
        if(m_LogLevel >= LogLevelError)
            cout << "[ERROR]: " << message << '\n';
    }
    void Warn(const char* message) {
        if(m_LogLevel >= LogLevelWarn)
            cout << "[WARNING]: " << message << '\n';
    }
    void Info(const char* message) {
        if(m_LogLevel >= LogLevelInfo)
            cout << "[INFO]: " << message << '\n';
    }
};

int main() {
    Log log;
    log.setLevel(log.LogLevelError);       // even writing Log::LogLevelError works fine because enum is 
    log.setLevel(Log::LogLevelInfo);
    log.Warn("Hello this is a warning!!");
    log.Error("Error");
    log.Info("Info");
    return 0;
}