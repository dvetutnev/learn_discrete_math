// Learning discrete mathematics
// Dmitriy Vetutnev, 2018


#include "towns.h"

#include <algorithm>
#include <map>
#include <iostream>
#include <iomanip>
#include <cstdlib>


std::ostream& operator<< (std::ostream& os, const std::vector<Town>& towns) {
    auto comp = [](const Town& a, const Town& b) {
        return a.name.length() < b.name.length();
    };
    const auto maxNameLengthIt = std::max_element(std::cbegin(towns), std::cend(towns), comp);
    const std::size_t maxNameLength = maxNameLengthIt->name.length();

    const char latitude[] = "Latitude ";
    const char longitude[] = "Longitude";
    std::string rowSeparator(maxNameLength, '-');
    rowSeparator += '+';
    rowSeparator += std::string(sizeof(latitude) - 1, '-'); // Length without null terminator
    rowSeparator += '+';
    rowSeparator += std::string(sizeof(longitude) - 1, '-');
    rowSeparator += '+';

    os << rowSeparator << std::endl;
    os << std::left << std::setw(static_cast<int>(maxNameLength)) << "Name" << '|' << latitude << '|' << longitude << '|' << std::endl;
    os << rowSeparator << std::endl;

    os << std::showpos << std::setprecision(6);
    for (const auto& town : towns) {
        os << std::left << std::setw(static_cast<int>(maxNameLength)) << town.name << '|' << \
              std::right << std::setw(9) << town.latitude << '|' << \
              std::right << std::setw(9) << town.longitude << '|' << \
              std::endl;
        os << rowSeparator << std::endl;
    }

    return os;
}


using DistanceTowns = std::map<std::string, std::map<std::string, float>>;


std::ostream& operator<< (std::ostream& os, const DistanceTowns& table) {
    auto comp = [](const DistanceTowns::value_type& a, const DistanceTowns::value_type& b) {
        return a.first.length() < b.first.length();
    };
    const auto maxNameLengthIt = std::max_element(std::cbegin(table), std::cend(table), comp);
    const std::size_t maxNameLength = maxNameLengthIt->first.length();

    const int cellWidth = 5;

    std::string cellSeparator(cellWidth, '-');
    cellSeparator += '+';
    std::string rowSeparator(maxNameLength, '-');
    rowSeparator += '+';
    for (std::size_t i = 0; i < table.size(); i++) {
        rowSeparator += cellSeparator;
    }

    // First line header
    const std::string corner(maxNameLength, ' ');
    os << corner << '+';
    for (std::size_t i = 0; i < table.size(); ++i) {
        os << cellSeparator;
    }
    os << std::endl;
    // Next header lines
    for (std::size_t i = maxNameLength; i > 0; --i) {
        os << corner << '|';
        for (const auto& entry : table) {
            const std::string& name = entry.first;
            const std::size_t length = name.length();
            if (i <= length) {
                os << ' ' << ' ' << name[length - i] << ' ' << ' ';
            }
            else {
                os << ' ' << ' ' << ' ' << ' ' << ' ';
            }
            os << '|';
        }
        os << std::endl;
    }

    os << rowSeparator << std::endl;
    // Data lines
    for (const auto& row : table) {
        const std::string& name = row.first;
        os << std::setw(static_cast<int>(maxNameLength)) << std::left << name <<'|';
        const std::map<std::string, float>& columns = row.second;
        for (const auto& col : columns) {
            os << std::setw(cellWidth) << std::right << std::noshowpos << std::setprecision(4) << col.second << '|';
        }
        os << std::endl << rowSeparator << std::endl;
    }

    return os;
}


static const DistanceTowns distanceTowns = {
    { "NY", {

          {"NY", 1234.6f}, {"Ryazan", 1.2345678f}, {"Metropolis", 99.645f} }
    },
    { "Ryazan", {

          {"NY", 0.0f}, {"Ryazan", 0.0f}, {"Metropolis", 0.0f} }
    },
    { "Metropolis", {

          {"Ny", 0.0f}, {"Ryazan", 0.0f}, {"Metropolis", 0.0f} }
    }
};


int main(int, char**) {
    const std::vector<Town> towns = generate();
    for (const auto& town : towns) {
        std::cout << town.name << "\t\t" << town.latitude << '\t' << town.longitude << std::endl;
    }

    std::cout << towns << std::endl;
    std::cout << distanceTowns << std::endl;

    const float a = 1234.5682646481f;
    std::cout << std::setw(5) << std::setprecision(4) << std::noshowpos << a << std::endl;

    return EXIT_SUCCESS;
}

