// Learning discrete mathematics
// Dmitriy Vetutnev, 2018


#include "towns.h"

#include <algorithm>
#include <map>
#include <cmath>
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

    // Header
    const std::string corner(maxNameLength, ' ');
    os << corner << '+';
    for (std::size_t i = 0; i < table.size(); ++i) {
        os << cellSeparator;
    }
    os << std::endl << corner << '|';
    for (const auto& row : table) {
        const std::string& name = row.first;
        for (unsigned int i = 0; i < cellWidth; ++i) {
            os << (i < name.length() ? name[i] : ' ');
        }
        os << '|';
    }
    os << std::endl << rowSeparator << std::endl;
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


DistanceTowns calcDistanceTowns(const std::vector<Town>& towns) {
    DistanceTowns result;
    for (const Town& row : towns) {
        std::map<std::string, float> rowResult;
        for (const Town& column : towns) {
            if (row.name == column.name) {
                rowResult.emplace(column.name, 0.f);
            }
            else {
                const float distance = std::hypotf(row.latitude - column.latitude, row.longitude - column.longitude);
                rowResult.emplace(column.name, distance);
            }
        }
        result.emplace(row.name, std::move(rowResult));
    }
    return result;
}


std::pair<float, std::vector<std::string>> brutforce(const DistanceTowns& distanceTowns) {
    std::vector<std::string> names;
    names.resize(distanceTowns.size());
    auto extractName = [](const DistanceTowns::value_type& row) -> std::string {
        return row.first;
    };
    std::transform(std::cbegin(distanceTowns), std::cend(distanceTowns), std::begin(names), extractName);

    auto nextPermutation = [](std::vector<std::string>::iterator first, std::vector<std::string>::iterator last) -> bool {
        if (first == last) {
            return false;
        }

        std::vector<std::string>::iterator i = last;
        if (first == --i) {
            return false;
        }

        while (true) {
            std::vector<std::string>::iterator i1, i2;

            i1 = i;
            if (*--i < *i1) {
                i2 = last;
                while (!(*i < *--i2))
                    ;
                std::iter_swap(i, i2);
                std::reverse(i1, last);
                return true;
            }
            if (i == first) {
                std::reverse(first, last);
                return false;
            }
        }
    };

    float minPathLength = 0.f;
    do {
        float pathLength = 0.f;
        auto it = std::cbegin(names);
        const auto itEnd = std::cend(names);
        for (;;) {
            auto itNext = it;
            ++itNext;
            if (itNext == itEnd) {
                break;
            }
            pathLength += distanceTowns.at(*it).at(*itNext);
            it = itNext;
        }
        if (std::isfinite(minPathLength) || std::isgreater(minPathLength, pathLength)) {
            minPathLength = pathLength;
        }
    } while (nextPermutation(std::begin(names), std::end(names)));

    return std::make_pair(minPathLength, std::move(names));
}


int main(int, char**) {
    const std::vector<Town> towns = generate();
    const DistanceTowns distanceTowns = calcDistanceTowns(towns);

    std::cout << towns << std::endl;
    std::cout << distanceTowns << std::endl;

    const auto brutforceResult = brutforce(distanceTowns);
    std::cout << "Brutforce path length: " << brutforceResult.first << std::endl;
    std::cout << "Brutforce path: " << std::endl;
    for (const auto& name : brutforceResult.second) {
        std::cout << name << std::endl;
    }

    return EXIT_SUCCESS;
}

