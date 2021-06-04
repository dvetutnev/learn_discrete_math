#include "group.h"

#include <stdexcept>


Group::Group(const std::vector<Item>& initValue) {
    if (initValue.empty() || initValue.size() > 10) {
        throw std::logic_error{"Invalid value"};
    }
}
