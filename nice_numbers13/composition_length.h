#pragma once

#include "number.h"

#include <list>
#include <algorithm>
#include <numeric>
#include <cassert>


// k - number, n - digits
inline std::size_t compositionLength(unsigned int k, unsigned char n, unsigned char base = 10) {
    if (n == 0) {
        return (k > 0) ? 0 : 1;
    }

    std::size_t result = 0;
    for (unsigned char j = 0; j < base && j <= k; j++) {
        result += compositionLength(k - j, n - 1);
    }

    return result;
}


namespace bruteforce {

inline Number maxNumber(unsigned char digits) {
    assert(digits > 0);

    std::list<Digit> l;
    std::fill_n(std::back_inserter(l), digits, Digit{12});

    return Number{std::begin(l), std::end(l)};
}

inline std::size_t compositionLength13(unsigned int k, unsigned char digits) {
    const Number top = maxNumber(digits);

    auto sumDigits = [](const Number& n) -> unsigned int {
        auto sum = [](unsigned int s, const Digit& d) -> unsigned int {
            return s + d.raw();
        };
        return std::accumulate(std::begin(n), std::end(n), 0, sum);
    };

    std::size_t result = 0;
    Number n{};
    for (;;) {
        if (sumDigits(n) == k) {
            result++;
        }
        if (n != top) {
            n = n + Digit{1};
        }
        else {
            break;
        }
    }

    return result;
}

} // namespace bruteforce
