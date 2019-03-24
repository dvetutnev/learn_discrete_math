// Learning discrete mathematics
// Dmitriy Vetutnev, 2018


#include "towns.h"

#include <algorithm>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdlib>


std::ostream& operator<< (std::ostream& os, const std::vector<Town>& towns) {
    auto comp = [](const Town& a, const Town&b) {
        return a.name.length() < b.name.length();
    };
    const auto maxNameLengthIt = std::max_element(std::cbegin(towns), std::cend(towns), comp);
    const int maxNameLength = static_cast<int>(maxNameLengthIt->name.length());

    std::ostringstream ss;
    ss << std::left << std::setw(maxNameLength) << "Name" << '|' << \
          std::left << std::setw(8) << "Lat" << '|' << \
          std::left << std::setw(8) << "Long" << '|';
    const std::string header = ss.str();
    const std::string lineSeparator(header.length(), '-');

    os << lineSeparator << std::endl;
    os << header << std::endl;
    os << lineSeparator << std::endl;

    os << std::showpos << std::setprecision(6);
    for (const auto& town : towns) {
        os << std::left << std::setw(maxNameLength) << town.name << '|' << \
              std::right << std::setw(8) << town.latitude << '|' << \
              std::right << std::setw(8) << town.longitude << '|' << \
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

