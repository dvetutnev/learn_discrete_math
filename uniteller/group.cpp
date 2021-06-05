#include "group.h"


Group::Group(const Symbol& s, const Digit& d)
    :
      symbol{s},
      digit{d}
{}

std::string Group::get() const {
    return std::string{symbol.get(), digit.get()};
}

bool Group::increment() {
    bool digitOverflow = digit.increment();
    if (digitOverflow) {
        bool symbolOverflow = symbol.increment();
        return symbolOverflow;
    }

    return false;
}
