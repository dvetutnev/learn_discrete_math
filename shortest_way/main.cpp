// Learning discrete mathematics
// Find shortest way
// Dmitriy Vetutnev, 2019


#include "shortest_way.h"

#include <iostream>
#include <cstdlib>


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

    const auto primeResult = prime(distanceTowns);
    std::cout << "Prime path length: " << primeResult.first << std::endl;
    std::cout << "Prime path: " << std::endl;
    for (const auto& name : primeResult.second) {
        std::cout << name << std::endl;
    }

    return EXIT_SUCCESS;
}
