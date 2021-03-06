// Learning discrete mathematics
// Find shortest way
// Dmitriy Vetutnev, 2019


#include "shortest_way.h"

#include <cmath>
#include <algorithm>
#include <iostream>
#include <iomanip>


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


std::pair<float, std::list<std::string>> brutforce(const DistanceTowns& distanceTowns) {
    std::list<std::string> names;
    auto extractName = [](const DistanceTowns::value_type& row) -> std::string {
        return row.first;
    };
    std::transform(std::cbegin(distanceTowns), std::cend(distanceTowns), std::back_inserter(names), extractName);

    auto nextPermutation = [](auto first, auto last) -> bool {
        if (first == last) {
            return false;
        }

        decltype(first) i = last;
        if (first == --i) {
            return false;
        }

        while (true) {
            decltype(first) i1, i2;

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
    std::list<std::string> minPath;
    do {
        float pathLength = 0.f;
        auto it = std::cbegin(names);
        const auto itEnd = std::cend(names);
        for (;;) {
            const auto itNext = std::next(it);
            if (itNext == itEnd) {
                break;
            }
            pathLength += distanceTowns.at(*it).at(*itNext);
            it = itNext;
        }
        if (std::isless(pathLength, minPathLength) || minPathLength == 0.f) {
            minPathLength = pathLength;
            minPath = names;
        }
    } while (nextPermutation(++std::begin(names), std::end(names)));

    return std::make_pair(minPathLength, std::move(minPath));
}


std::pair<float, std::list<std::string>> prime(const DistanceTowns& distanceTowns) {
    std::list<std::string> names;
    auto extractName = [](const DistanceTowns::value_type& row) -> std::string {
        return row.first;
    };
    std::transform(std::cbegin(distanceTowns), std::cend(distanceTowns), std::back_inserter(names), extractName);

    float pathLength = 0.f;
    std::list<std::string> path{names.front()}; names.pop_front();
    do {
        const std::string& lastName = path.back();
        const auto& row = distanceTowns.at(lastName);

        auto itName = std::cbegin(names);
        auto itCell = row.find(*itName);

        ++itName;

        for (; itName != std::cend(names); ++itName) {
            const auto it = row.find(*itName);
            if (std::isless(it->second, itCell->second)) {
                itCell = it;
            }
        }

        const std::string& nextName = itCell->first;

        pathLength += itCell->second;
        path.push_back(nextName);

        names.remove(nextName);
    } while (!names.empty());

    return std::make_pair(pathLength, std::move(path));
}


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
