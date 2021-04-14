#ifndef UTILS_H
#define UTILS_H

namespace String {
    std::string FormatChar(std::string string, char exp_char);
    std::string FormatString(std::string string, std::string exp_string);
}

namespace Log
{
    void Log(std::string level, std::string message, std::string sgr, std::string color);
    void Debug(std::string message);
    void Info(std::string message);
    void Warning(std::string message);
    void Error(std::string message);
}

#endif