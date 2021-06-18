#pragma once

#include "number.h"

#include <list>
#include <algorithm>
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
    Number top = maxNumber(digits);

    auto sumDigits = [](const Number& n) -> unsigned int {
        unsigned int result = 0;
        for (auto it = std::begin(n); it != std::end(n); ++it) {
            result += it->raw();
        }
        return result;
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
