#pragma once

#include <stdexcept>


class Digit
{
public:
    Digit(unsigned char v = 0);

    Digit(const Digit&) = default;
    Digit& operator= (const Digit&) = default;

    struct Less;
    struct Equal;

private:
    static const unsigned char top = 12;
    unsigned char value;
};


inline Digit::Digit(unsigned char v)
    :
      value{v}
{
    if (v > top) {
        throw std::logic_error{"Digit: overflow"};
    }
}


struct Digit::Less
{
    bool operator()(const Digit& a, const Digit& b) const {
        return a.value < b.value;
    }
};

struct Digit::Equal
{
    bool operator()(const Digit& a, const Digit& b) const {
        return a.value == b.value;
    }
};

inline bool operator< (const Digit& a, const Digit& b) {
    return Digit::Less{}(a, b);
}

inline bool operator== (const Digit& a, const Digit& b) {
    return Digit::Equal{}(a, b);
}

inline bool operator!= (const Digit& a, const Digit& b) {
    return !(a == b);
}
