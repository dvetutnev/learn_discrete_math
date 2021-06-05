#pragma once

#include "symbol.h"
#include "digit.h"

#include <string>


class Group
{
public:
    Group(const Symbol&, const Digit&);

    std::string get() const;
    bool increment();

private:
    Symbol symbol;
    Digit digit;
};

