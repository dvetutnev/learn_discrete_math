#pragma once

#include "digit.h"
#include <array>


class Number
{
public:
    using Value = std::array<Digit, 13>;

    inline static const Value defaultValue = {
        Digit{0}, // 1
        Digit{0}, // 2
        Digit{0}, // 3
        Digit{0}, // 4
        Digit{0}, // 5
        Digit{0}, // 6
        Digit{0}, // 7
        Digit{0}, // 8
        Digit{0}, // 9
        Digit{0}, // 10
        Digit{0}, // 11
        Digit{0}, // 12
        Digit{0}, // 13
    };

    Number(const Value& v = defaultValue);

    Number(const Number&) = default;
    Number& operator= (const Number&) = default;

private:
    Value value;
};


inline Number::Number(const Value& v)
    :
      value{v}
{}
