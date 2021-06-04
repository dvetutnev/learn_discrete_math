#include "group.h"

#include <stdexcept>


namespace {

void checkValue(const std::vector<Item>& value) {
    if (value.empty() || value.size() > 10) {
        throw std::logic_error{"Invalid value"};
    }
}

} // Anonymous namespace


Group::Group(const std::vector<Item>& initValue) {
    checkValue(initValue);
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

void Group::set(const std::vector<Item>& value) {
    checkValue(value);
    chunks = value;
}
