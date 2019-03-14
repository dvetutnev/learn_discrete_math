/*
 * Generate townnames with coordinates.
 * Dmitriy Vetutnev, 2018
*/


#include <namegen.h>

#include <iostream>
#include <fstream>
#include <iomanip>
#include <random>
#include <cstdlib>
#include <cctype>


int main(int argc, char* argv[]) {

    unsigned countTowns;
    std::string filename;

    try {
        if (argc < 3) {
            throw std::logic_error{"Invalid arguments"};
        }
        countTowns = static_cast<unsigned>(std::stoul(argv[1]));
        filename = argv[2];
    }
    catch (const std::logic_error& e) {
        std::cout << e.what() << std::endl;
        std::cout << "Usage: towns_generator count dir/towns.h" << std:: endl;
        return EXIT_FAILURE;
    }

    std::ofstream file{filename, std::ios::binary};
    std::string content =
R"(/* automatically generated */

#pragma once


#include <string>
#include <vector>


struct Town
{
    std::string name;
    float latitude;
    float longitude;
};


inline const std::vector<Town>& generate() {
    static const std::vector<Town> towns = {
)";
    file << content;

    std::random_device randomDevice;
    std::mt19937 randomGenerator{randomDevice()};
    std::vector<float> interval{-90,  +90};
    std::vector<float> weight{1};
    std::piecewise_constant_distribution<float> distribution{std::cbegin(interval), std::cend(interval), std::cbegin(weight)};
    NameGen::Generator nameGenerator{FANTASY_N_L};

    for (unsigned i = 1; i <= countTowns; i++) {
        std::string townName = nameGenerator.toString();
        townName[0] = static_cast<char>(std::toupper(townName[0]));

        file << "        {" \
             << "\"" << townName << "\"," \
             << ' ' << std::showpos << std::showpoint << std::fixed << distribution(randomGenerator) << "f," \
             << ' ' << std::showpos << std::showpoint << std::fixed << distribution(randomGenerator) << 'f' \
             << '}';

        if (i < countTowns) {
            file << ',';
        }

        file << '\n';
    }

    content =
R"(    };
    return towns;
}
)";
    file << content;

    return EXIT_SUCCESS;
}
