#pragma once


#include <vector>
#include <set>
#include <utility>
#include <optional>
#include <cassert>


namespace bruteforce {


// Return pair numbers, not index
inline std::optional<std::pair<std::size_t, std::size_t>> findPair(const std::vector<std::size_t>& set, std::size_t sum) {
    for (auto externIt = std::begin(set); externIt != std::end(set); ++externIt) {
        for (auto internIt = std::begin(set); internIt != std::end(set); ++internIt) {
            if (externIt == internIt) {
                continue;
            }

            std::size_t first = *externIt;
            std::size_t second = *internIt;

            if (first + second == sum) {
                return std::make_pair(first, second);
            }
        }
    }

    return std::nullopt;
}


}


namespace sort {


inline std::optional<std::pair<std::size_t, std::size_t>> findPair(const std::vector<std::size_t>& input, std::size_t sum) {
    // std::set is an associative container that contains a sorted set of unique objects of type Key
    // https://en.cppreference.com/w/cpp/container/set
    std::set<std::size_t> set = { std::begin(input), std::end(input) };
    assert(set.size() <= input.size());

    auto setIt = std::begin(set);
    auto inputIt = std::begin(input);
    auto end = std::end(set);

    for (; setIt != end; ++setIt, ++inputIt) {
        auto a = *setIt;
        auto b = *inputIt;

        if (a == b) {
            continue;
        }

        if (a + b == sum) {
            return std::make_pair(a, b);
        }
    }

    return std::nullopt;
}


}
