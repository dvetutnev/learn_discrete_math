#include "symbol.h"

#include <algorithm>
#include <stdexcept>


Symbol::Symbol(char c) {
    if (c < bottom || c > top) {
        throw std::logic_error{"Invalid symbol"};
    }

    auto it = std::find(std::begin(excluded), std::end(excluded), c);
    if (it != std::end(excluded)) {
        throw std::logic_error{"Invalid symbol"};
    }

    value = c;
}

char Symbol::get() const {
    return value;
}

bool Symbol::increment() {
    bool isOverflow = false;

    for (;;) {
        if (value < top) {
            ++value;
        }
        else {
            value = bottom;
            isOverflow = true;
        }

        auto it = std::find(std::begin(excluded), std::end(excluded), value);
        if (it == std::end(excluded)) {
            break;
        }
    }

    return isOverflow;
}

const std::vector<char> Symbol::excluded = {'D', 'F', 'G', 'J', 'M', 'Q', 'V'};
