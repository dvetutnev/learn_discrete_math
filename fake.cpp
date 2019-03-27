// Learning discrete mathematics
// Dmitriy Vetutnev, 2018


#include "towns.h"

#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstdlib>


std::ostream& operator<< (std::ostream& os, const std::vector<Town>& towns) {
    auto comp = [](const Town& a, const Town&b) {
        return a.name.length() < b.name.length();
    };
    const auto maxNameLengthIt = std::max_element(std::cbegin(towns), std::cend(towns), comp);
    const std::size_t maxNameLength = maxNameLengthIt->name.length();

    const char latitude[] = "Latitude ";
    const char longitude[] = "Longitude";
    std::string lineSeparator(maxNameLength, '-');
    lineSeparator += '+';
    lineSeparator += std::string(sizeof(latitude) - 1, '-'); // Length without null terminator
    lineSeparator += '+';
    lineSeparator += std::string(sizeof(longitude) - 1, '-');
    lineSeparator += '+';

    os << lineSeparator << std::endl;
    os << std::left << std::setw(static_cast<int>(maxNameLength)) << "Name" << '|' << latitude << '|' << longitude << '|' << std::endl;
    os << lineSeparator << std::endl;

    os << std::showpos << std::setprecision(6);
    for (const auto& town : towns) {
        os << std::left << std::setw(static_cast<int>(maxNameLength)) << town.name << '|' << \
              std::right << std::setw(9) << town.latitude << '|' << \
              std::right << std::setw(9) << town.longitude << '|' << \
              std::endl;
        os << lineSeparator << std::endl;
    }

    return os;
}


int main(int, char**) {
    const std::vector<Town> towns = generate();
    for (const auto& town : towns) {
        std::cout << town.name << "\t\t" << town.latitude << '\t' << town.longitude << std::endl;
    }

    std::cout << towns << std::endl;

    return EXIT_SUCCESS;
}

