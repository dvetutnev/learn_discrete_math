#pragma once

#include "item.h"

#include <vector>


class Group
{
public:
    Group(const std::vector<Item>&);

    std::string get() const;
};
