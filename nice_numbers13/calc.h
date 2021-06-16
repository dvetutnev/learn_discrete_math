#pragma once

#include "number.h"


namespace bruteforce
{

inline std::size_t calc() {
    std::size_t count = 0;

    Number end{{
        Digit{12},   // 1
        Digit{12},   // 2
        Digit{12},   // 3
        Digit{12},   // 4
        Digit{12},   // 5
        Digit{12},   // 6
        Digit{12},   // 7
        Digit{12},   // 8
        Digit{12},   // 9
        Digit{12},   // 10
        Digit{12},   // 11
        Digit{12},   // 12
        Digit{12},   // 13
    }};

    auto n = Number{};
    for (;;) {
        if (isNice(n)) {
            count++;
        }
        if (n != end) {
            n = n + Digit{1};
        }
        else {
            break;
        }
    }

    return count;
}

std::size_t calcComp(const Number& sum) {
    std::size_t count = 0;

    Number n{};
    Number end{
        Digit{12},   // 1
        Digit{12},   // 2
        Digit{12},   // 3
        Digit{12},   // 4
        Digit{12},   // 5
        Digit{12},   // 6
    };


    while (n != end) {
        auto beginIt = std::begin(n) + 7;
        auto endIt = std::end(n);

        Number s = digitsSum(beginIt, endIt);
        if (s == sum) {
            count++;
        }

        n = n + Digit{1};
    }

    return count;
}

}
