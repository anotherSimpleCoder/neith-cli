#include "help.hpp"

void Help::help() {
    std::cout << "Commands:" << std::endl;
    std::cout << "\tnew <project-name>\t\tStart a new Neith project" << std::endl;
    std::cout << "\tserve\t\t\t\tStarts the development server" << std::endl;
    std::cout << "\tcomponent <component-same>\tCreate a new component" << std::endl;
    std::cout << "\tservice <service-name>\t\tCreate a Service" << std::endl;
    std::cout << "\n";
}