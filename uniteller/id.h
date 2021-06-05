#pragma once

#include "item.h"

#include <vector>


class Id
{
public:
    Id(const std::vector<Item>&);

    std::string get() const;
    void set(const std::vector<Item>&);
    bool increment();

private:
    std::vector<Item> chunks;

    bool increment(std::vector<Item>::iterator);

    static const std::size_t maxChunks = 10;
};
