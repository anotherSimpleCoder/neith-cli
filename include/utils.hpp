#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>
#include <fstream>
#include <string>

#ifdef _WIN32
    #include <Windows.h>
#else
    #include <unistd.h>
    #include <sys/wait.h>
#endif

namespace Utils {
    void titleCard();
    std::string toTitleCase(std::string string);
    void run(std::string command);
    void writeFile(std::string filename, std::string content);
};

#endif