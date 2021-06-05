#include "id.h"

#include <stdexcept>


namespace {

void checkValue(const std::vector<Group>& value) {
    if (value.empty() || value.size() > 10) {
        throw std::logic_error{"Invalid value"};
    }
}

} // Anonymous namespace


Id::Id(const std::vector<Group>& initValue) {
    checkValue(initValue);
    chunks = initValue;
}

std::string Id::get() const {
    std::lock_guard{mtx};

    const Group& first = chunks.back();
    std::string result = first.get();

    for (auto it = std::next(std::rbegin(chunks)); it != std::rend(chunks); ++it) {
        result += '-' + it->get();
    }

    return result;
}

void Id::set(const std::vector<Group>& value) {
    std::lock_guard{mtx};

    checkValue(value);
    chunks = value;
}

bool Id::increment() {
    std::lock_guard{mtx};

    return increment(std::begin(chunks));
}

bool Id::increment(std::vector<Group>::iterator currentIt) {
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
                chunks = std::vector<Group>{ {'A', '1'} };
                isAllOverflow = true;
            }
        }
    }

    return isAllOverflow;
}

std::string Id::next() {
    increment();
    return get();
}
