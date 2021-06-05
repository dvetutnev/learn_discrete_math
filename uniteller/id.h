#pragma once

#include "group.h"

#include <vector>


class Id
{
public:
    Id(const std::vector<Group>&);

    std::string get() const;
    void set(const std::vector<Group>&);

    bool increment();
    std::string next();

private:
    std::vector<Group> chunks;

    bool increment(std::vector<Group>::iterator);

    static const std::size_t maxChunks = 10;
};
