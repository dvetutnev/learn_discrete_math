#pragma once

#include "item.h"

#include <vector>


class Group
{
public:
    Group(const std::vector<Item>&);

    std::string get() const;
    void set(const std::vector<Item>&);

private:
    std::vector<Item> chunks;
};
