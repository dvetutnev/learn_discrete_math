#include "item.h"

Item::Item(const Symbol& s, const Digit& d)
    :
      symbol{s},
      digit{d}
{}

std::string Item::get() const {
    return std::string{symbol.get(), digit.get()};
}
