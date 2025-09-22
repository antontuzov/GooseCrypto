#include "../../include/utils/logger.h"
#include <ctime>
#include <iomanip>
#include <sstream>
#include <iostream>

Logger::Logger(LogLevel level) : level(level) {}

void Logger::set_level(LogLevel level) {
    this->level = level;
}

void Logger::debug(const std::string& message) {
    if (static_cast<int>(level) <= static_cast<int>(LogLevel::DEBUG)) {
        log(LogLevel::DEBUG, message);
    }
}

void Logger::info(const std::string& message) {
    if (static_cast<int>(level) <= static_cast<int>(LogLevel::INFO)) {
        log(LogLevel::INFO, message);
    }
}

void Logger::warn(const std::string& message) {
    if (static_cast<int>(level) <= static_cast<int>(LogLevel::WARN)) {
        log(LogLevel::WARN, message);
    }
}

void Logger::error(const std::string& message) {
    if (static_cast<int>(level) <= static_cast<int>(LogLevel::ERROR)) {
        log(LogLevel::ERROR, message);
    }
}

void Logger::log(LogLevel logLevel, const std::string& message) {
    // Get current time
    std::time_t now = std::time(nullptr);
    std::tm* tm = std::localtime(&now);
    
    // Format time
    std::ostringstream time_stream;
    time_stream << std::put_time(tm, "%Y-%m-%d %H:%M:%S");
    
    // Output log message
    std::cout << "[" << time_stream.str() << "] [" << level_to_string(logLevel) << "] " << message << std::endl;
}

std::string Logger::level_to_string(LogLevel level) {
    switch (static_cast<int>(level)) {
        case static_cast<int>(LogLevel::DEBUG): return "DEBUG";
        case static_cast<int>(LogLevel::INFO):  return "INFO";
        case static_cast<int>(LogLevel::WARN):  return "WARN";
        case static_cast<int>(LogLevel::ERROR): return "ERROR";
        default:                                return "UNKNOWN";
    }
}