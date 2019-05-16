// Learning discrete mathematics
// Find shortest way
// Dmitriy Vetutnev, 2019


#pragma once


#include "towns.h"

#include <vector>
#include <map>
#include <list>
#include <utility>
#include <iosfwd>


using DistanceTowns = std::map<std::string, std::map<std::string, float>>;


DistanceTowns calcDistanceTowns(const std::vector<Town>& towns);

std::pair<float, std::list<std::string>> brutforce(const DistanceTowns& distanceTowns);
std::pair<float, std::list<std::string>> prime(const DistanceTowns& distanceTowns);

std::ostream& operator<< (std::ostream& os, const std::vector<Town>& towns);
std::ostream& operator<< (std::ostream& os, const DistanceTowns& table);
