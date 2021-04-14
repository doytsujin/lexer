#include <iostream>
#include "header/utils.hpp"

std::string String::FormatChar(std::string string, char exp_char)
{
    for (size_t i = 0; i < string.length(); ++i)
    {
        if (string[i] == '%')
        {
            string[i] = exp_char;
        }
    }
    return string;
}

std::string String::FormatString(std::string string, std::string exp_string)
{
    for (size_t i = 0; i < string.length(); ++i)
    {
        if (string[i] == '%')
        {
            string.replace(i, 1, exp_string);
        }
    }
    return string;
}

// SGR (Select Graphic Rendition) parameters
void Log::Log(std::string level, std::string message, std::string sgr, std::string color)
{
    std::cout << "[\033[" << sgr << ";" << color << "m " << level << " \033[0m] " << message << std::endl;
    ;
}

void Log::Debug(std::string message)
{
    Log::Log("DEBUG", message, "1", "95");
}

void Log::Info(std::string message)
{
    Log::Log("INFO", message, "1", "96");
}

void Log::Warning(std::string message)
{
    Log::Log("WARNING", message, "1", "93");
}

void Log::Error(std::string message)
{
    Log::Log("ERROR", message, "1", "91");
    exit(1);
}