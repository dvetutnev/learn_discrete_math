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

bool Group::increment() {
    return increment(std::begin(chunks));
}

bool Group::increment(std::vector<Item>::iterator currentIt) {
    bool isAllOverflow = false;

    bool isOverflow = currentIt->increment();
    if (isOverflow) {
        auto nextIt = std::next(currentIt);
        if (nextIt != std::end(chunks)) {
            isAllOverflow = increment(nextIt);
        }
        else {
            if (chunks.size() < maxChunks) {
                chunks.emplace_back('A', '1');
            }
            else {
                chunks = std::vector<Item>{ {'A', '1'} };
                isAllOverflow = true;
            }
        }
    }

    return isAllOverflow;
}
