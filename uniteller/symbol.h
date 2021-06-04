#pragma once

#include <vector>


class Symbol
{
public:
    Symbol(char);

    Symbol(const Symbol&) = default;
    Symbol& operator= (const Symbol&) = default;

    char get() const;
    bool increment();

private:
    char value;

    static const char bottom = 'A';
    static const char top = 'Z';
    static const std::vector<char> excluded;
};
