#ifndef CREATOR_HPP
#define CREATOR_HPP

#include <string>
#include <sstream>
#include <fstream>
#include "utils.hpp"

namespace Creator {
    void createService(std::string name);
    void createComponent(std::string name);
}

#endif