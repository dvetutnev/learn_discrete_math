#pragma once

#include <vector>


class Symbol
{
public:
    Symbol(char);

    char get() const;
    bool increment();

private:
    char value;

    const char bottom = 'A';
    const char top = 'Z';
    const std::vector<char> excluded = {'D', 'F', 'G', 'J', 'M', 'Q', 'V'};
};
