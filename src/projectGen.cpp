#include "projectGen.hpp"

void writeMainTS(std::string projName) {
    std::ostringstream codeStream;
    codeStream << "import { NeithServer } from 'https://github.com/anotherSimpleCoder/neith/raw/main/mod.ts';" << std::endl;
    codeStream << "import { routes } from './routes.ts';" << std::endl;
    codeStream << "\n";
    codeStream << "NeithServer" << std::endl;
    codeStream << "\t.fromRoutes(routes)" << std::endl;
    codeStream << "\t.serve(3000);" << std::endl;

    Utils::writeFile(projName + "/main.ts", codeStream.str());
}

void writeRoutes(std::string projName) {
    std::ostringstream codeStream;
    codeStream << "import {Route} from 'https://github.com/anotherSimpleCoder/neith/raw/main/mod.ts';" << std::endl;
    codeStream << "\n";
    codeStream << "export const routes: Route[] = [];" << std::endl;

    Utils::writeFile(projName + "/routes.ts", codeStream.str());
}

void ProjectGen::generate() {
    std::string name;
    std::cout << "Project name: ";
    std::cin >> name;
    std::cout << "\n";
    std::cout << name << std::endl;

    if(!std::filesystem::create_directory(name)) {
        std::cout << "FileError: Couldn't create directory " << name << std::endl;
        return;
    }

    Utils::run("cmd /c cd " + name + " && deno init");
    // Utils::run("cmd /c cd " + name + " && git clone https://github.com/anotherSimpleCoder/neith");
    writeRoutes(name);
    writeMainTS(name);
    Utils::run("cmd /c cd " + name + " && deno cache .");
}