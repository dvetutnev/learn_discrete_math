#pragma once


#include <random>


auto getRandomGenerator(int a, int b) {
    std::random_device rd;
    auto result = [gen = std::mt19937{rd()}, distrib = std::uniform_int_distribution<>{a, b}] () mutable {
        return distrib(gen);
    };

    return result;
}
