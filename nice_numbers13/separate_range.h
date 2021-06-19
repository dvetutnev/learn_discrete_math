#pragma once

#include <utility>
#include <vector>
#include <algorithm>
#include <cmath>


using Range = std::pair<unsigned int, unsigned int>;

inline std::vector<Range> separateRange(Range range, unsigned int count) {
    unsigned int total = range.second - range.first + 1;
    count = std::min(count, total);
    unsigned int step = std::lround(static_cast<float>(total) / count);

    std::vector<Range> result;
    for (unsigned int i = 0; i < count; i++) {
        unsigned int first = range.first + step * i;
        if (first > range.second) {
            break;
        }
        unsigned int second = first + step - 1;
        result.emplace_back(first, second);
    };
    result.back().second = range.second;

    return result;
}
