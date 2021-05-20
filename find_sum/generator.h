#pragma once


#include <random>
#include <vector>
#include <algorithm>


inline auto getRandomGenerator(std::size_t a, std::size_t b) {
    std::random_device rd;
    auto result = [gen = std::mt19937{rd()}, distrib = std::uniform_int_distribution<std::size_t>{a, b}] () mutable {
        return distrib(gen);
    };

    return result;
}


inline std::vector<std::size_t> generateSet(std::size_t size) {
    std::size_t hight = std::max(999ul, size);
    auto generator = getRandomGenerator(1, hight);

    std::vector<std::size_t> result;
    result.reserve(size);

    do {
        auto number = generator();
        auto it = std::find(std::begin(result), std::end(result), number);
        if (it == std::end(result)) {
            result.push_back(number);
        }
    }
    while (result.size() < size);

    return result;
}
