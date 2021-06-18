#pragma once

#include <cstddef>


// k - number, n - digits
std::size_t compositionLength(unsigned int k, unsigned char n, unsigned char base = 10) {
    if (n == 0) {
        return (k > 0) ? 0 : 1;
    }

    std::size_t result = 0;
    for (unsigned char j = 0; j < base && j <= k; j++) {
        result += compositionLength(k - j, n - 1);
    }

    return result;
}

