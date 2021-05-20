#pragma once


#include <vector>
#include <utility>
#include <optional>


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
