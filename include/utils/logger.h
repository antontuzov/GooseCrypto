#ifndef GOOSECRYPTO_LOGGER_H
#define GOOSECRYPTO_LOGGER_H

#include <string>
#include <iostream>

enum class LogLevel {
    DEBUG,
    INFO,
    WARN,
    ERROR
};

class Logger {
private:
    LogLevel level;
    
public:
    Logger(LogLevel level = LogLevel::INFO);
    
    void set_level(LogLevel level);
    
    void debug(const std::string& message);
    void info(const std::string& message);
    void warn(const std::string& message);
    void error(const std::string& message);
    
private:
    void log(LogLevel level, const std::string& message);
    std::string level_to_string(LogLevel level);
};

#endif // GOOSECRYPTO_LOGGER_H