#include "group.h"

#include <stdexcept>


Group::Group(const std::vector<Item>& initValue) {
    if (initValue.empty() || initValue.size() > 10) {
        throw std::logic_error{"Invalid value"};
    }

    chunks = initValue;
}

std::string Group::get() const {
    const Item& first = chunks.back();
    std::string result = first.get();

    for (auto it = std::next(std::rbegin(chunks)); it != std::rend(chunks); ++it) {
        result += '-' + it->get();
    }

    return result;
}
