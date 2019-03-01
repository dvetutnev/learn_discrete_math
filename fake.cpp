// Learning discrete mathematics
// Dmitriy Vetutnev, 2018


#include "towns.h"
#include <iostream>
#include <cstdlib>


int main(int, char**) {
    for (const auto& town : generate()) {
        std::cout << town.name << "\t\t" << town.latitude << '\t' << town.longitude << std::endl;
    }
    return EXIT_SUCCESS;
}

