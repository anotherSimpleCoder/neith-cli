#ifndef ARGS_HPP
#define ARGS_HPP

#include <string>

namespace Args {
    typedef struct {
        int argc;
        std::string* argv;
    } Args;

    Args from(int argc, char** argv) {
        Args res {argc, new std::string[argc]};

        for(int i = 0; i < res.argc; i++) {
            res.argv[i] = argv[i];
        }

        return res;
    }
}

#endif