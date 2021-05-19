#pragma once


#include <random>
#include <set>
#include <algorithm>


inline auto getRandomGenerator(std::size_t a, std::size_t b) {
    std::random_device rd;
    auto result = [gen = std::mt19937{rd()}, distrib = std::uniform_int_distribution<std::size_t>{a, b}] () mutable {
        return distrib(gen);
    };

    return result;
}


inline std::set<int> generateSet(std::size_t size) {
    std::size_t hight = std::max(999ul, size);
    auto generator = getRandomGenerator(1, hight);

    std::set<int> result;

    do {
        int i = generator();
        result.insert(i);
    }
    while (result.size() < size);

    return result;
}
