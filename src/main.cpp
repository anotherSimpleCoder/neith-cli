#include <iostream>
#include <string>
#include <array>
#include "utils.hpp"
#include "help.hpp"
#include "args.hpp"
#include "creator.hpp"
#include "projectGen.hpp"

void route(Args::Args args) {
    if(args.argv[1] == "new") {
        ProjectGen::generate();
        return;
    }

    if(args.argv[1] == "service") {
        Creator::createService(args.argv[2]);
        return;
    }

    if(args.argv[1] == "component") {
        Creator::createComponent(args.argv[2]);
        return;
    }
}

int main(int argc, char** argv) {
    if(argc < 2) {
        Utils::titleCard();
        Help::help();
        return 0;
    }

    route(Args::from(argc, argv));

    return 0;
}