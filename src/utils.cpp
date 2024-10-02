#include <cctype>
#include <cstring>
#include "banner.hpp"
#include "utils.hpp"

void Utils::titleCard() {
    std::cout << banner_txt << std::endl;
}

std::string Utils::toTitleCase(std::string string) {
    int stringLength = string.length();
    char* cString = new char[stringLength + 1];
    strcpy(cString, string.c_str());

    cString[0] = std::toupper(cString[0]);

    return std::string(cString);
}


#ifdef _WIN32
void runWindows(std::string command) {
    STARTUPINFO si;
    PROCESS_INFORMATION pi;

    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));

    auto process = CreateProcess(
        NULL,
        const_cast<LPSTR>(command.c_str()),
        NULL,
        NULL,
        FALSE,
        0,
        NULL,
        NULL,
        &si,
        &pi
    );

    if(!process) {
        std::cout << "ProcessError: Failed to create process: " << command << std::endl;
        std::cout << GetLastError() << std::endl;
        return;
    }

    WaitForSingleObject(pi.hProcess, INFINITE);

    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);
}
#else
void runUnix(std::string command) {
    pid_t pid = fork();

    if(pid < 0) {
        std::cout << "ProcessError: Failed to create process " << command << std::endl;
        return;
    } else if (pid == 0) {
        execlp("bash", command.c_str(), NULL);

        std::cout << "ProcessError: Failed to run " << command << std::endl;
        return;
    } else {
        wait(NULL);
        return;
    }
}
#endif

void Utils::run(std::string command) {
    #ifdef _WIN32
        runWindows(command);
    #else
        runUnix(command);
    #endif
}

void Utils::writeFile(std::string filename, std::string content) {
    std::ofstream outFile(filename);
    if(!outFile) {
        std::cout << "FileError: Couldn't create file " << filename << std::endl;
        return;
    }

    outFile << content;
    outFile.close();
}