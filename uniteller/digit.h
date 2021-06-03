#pragma once


class Digit
{
public:
    Digit(char);

    char get() const;
    bool increment();

private:
    char value;

    const char bottom = '1';
    const char top = '9';
};
