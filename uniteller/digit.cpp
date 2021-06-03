#include "digit.h"

#include <stdexcept>


Digit::Digit(char c) {
    if (c < bottom || c > top) {
        throw std::logic_error{"Invalid digit"};
    }

    value = c;
}

char Digit::get() const {
    return value;
}

bool Digit::increment() {
    if (value < top) {
        ++value;
        return false;
    }
    else {
        value = bottom;
        return true;
    }
}
