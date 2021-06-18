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
    struct Sum;

    static Sum sum(const Digit&, const Digit&);

    unsigned char raw() const;

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


inline unsigned char Digit::raw() const {
    return value;
}


struct Digit::Sum
{
    Digit value;
    bool carry;
};

inline Digit::Sum Digit::sum(const Digit& a, const Digit& b) {
    auto s = a.value + b.value;
    if (s <= top) {
        return Sum{
            Digit{static_cast<unsigned char>(s)},
            false
        };
    }
    else {
        return Sum{
            Digit{static_cast<unsigned char>(s - top)},
            true
        };
    }
}

inline Digit::Sum operator+ (const Digit& a, const Digit& b) {
    return Digit::sum(a, b);
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
