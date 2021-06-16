#pragma once

#include "digit.h"

#include <array>
#include <initializer_list>
#include <algorithm>


class Number
{
public:
    // Разряды расположены от старшего к младшему
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
    Number(std::initializer_list<Digit>);

    Number(const Number&) = default;
    Number& operator= (const Number&) = default;

    Value::const_iterator begin() const;
    Value::const_iterator end() const;

    friend Number operator+ (Number, const Digit&);

    struct Less;
    struct Equal;

private:
    Value value;
};


inline Number::Number(const Value& v)
    :
      value{v}
{}

inline Number::Number(std::initializer_list<Digit> l)
{
    auto itL = std::rbegin(l);
    auto itV = std::rbegin(value);
    for (; itL != std::rend(l) && itV != std::rend(value); ++itL, ++itV) {
        *itV = *itL;
    }
}


inline Number::Value::const_iterator Number::begin() const {
    return std::begin(value);
}

inline Number::Value::const_iterator Number::end() const {
    return std::end(value);
}


struct Number::Less
{
    bool operator()(const Number& a, const Number& b) const {
        auto itA = std::begin(a);
        auto itB = std::begin(b);
        for (; itA != std::end(a) && itB != std::end(b); ++itA, ++itB) {
            if (*itA == *itB) {
                continue;
            }
            else if (*itA < *itB) {
                return true;
            }
            else {
                return false;
            }
        }

        return false;
    }
};

struct Number::Equal
{
    bool operator()(const Number& a, const Number& b) const {
        return a.value == b.value;
    }
};


inline bool operator< (const Number& a, const Number& b) {
    return Number::Less{}(a, b);
}

inline bool operator== (const Number& a, const Number& b) {
    return Number::Equal{}(a, b);
}

inline bool operator!= (const Number& a, const Number& b) {
    return !(a == b);
}


inline Number operator+ (Number number, const Digit& digit) {
    auto it = std::rbegin(number.value);
    Digit::Sum sum = *it + digit;
    *it = sum.value;

    for (it = std::next(it); sum.carry; ++it) {
        if (it == std::rend(number.value)) {
            throw std::runtime_error{"Number::operator+: overflow"};
        }

        sum = *it + Digit{1};
        *it = sum.value;
    }

    return number;
}
