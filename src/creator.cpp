#include "creator.hpp"

void Creator::createService(std::string name) {
    std::ostringstream codeStream;

    codeStream << "'@service'" << std::endl;
    codeStream << "class " << Utils::toTitleCase(name) << "Service {}" << std::endl;

    Utils::writeFile(name + ".service.ts", codeStream.str());
}

void Creator::createComponent(std::string name) {
    Utils::writeFile(name + ".neith", "<p>" + name + " works!</p>");
}