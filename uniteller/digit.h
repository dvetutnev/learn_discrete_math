#pragma once


class Digit
{
public:
    Digit(char);

    Digit(const Digit&) = default;
    Digit& operator= (const Digit&) = default;

    char get() const;
    bool increment();

private:
    char value;

    static const char bottom = '1';
    static const char top = '9';
};
