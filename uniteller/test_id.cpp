#include <gtest/gtest.h>

#include <vector>
#include <algorithm>
#include <stdexcept>


class Symbol
{
public:
    Symbol(char);

    char get() const;
    bool increment();

private:
    char value;
    const std::vector<char> excluded = {'D', 'F', 'G', 'J', 'M', 'Q', 'V'};
};

Symbol::Symbol(char c) {
    if (c < 'A' || c > 'Z') {
        throw std::logic_error{"Invalid symbol"};
    }

    auto it = std::find(std::begin(excluded), std::end(excluded), c);
    if (it != std::end(excluded)) {
        throw std::logic_error{"Invalid symbol"};
    }

    value = c;
}

char Symbol::get() const {
    return value;
}

bool Symbol::increment() {
    for (;;) {
        value++;

        auto it = std::find(std::begin(excluded), std::end(excluded), value);
        if (it == std::end(excluded)) {
            break;
        }
    }

    return false;
}


TEST(Symbol, ctor) {
    ASSERT_NO_THROW( Symbol{'A'}; );

    ASSERT_ANY_THROW( Symbol{'a'} );
    ASSERT_ANY_THROW( Symbol{'z'} );

    ASSERT_ANY_THROW( Symbol{'D'}; );
    ASSERT_ANY_THROW( Symbol{'F'}; );
    ASSERT_ANY_THROW( Symbol{'G'}; );
    ASSERT_ANY_THROW( Symbol{'J'}; );
    ASSERT_ANY_THROW( Symbol{'M'}; );
    ASSERT_ANY_THROW( Symbol{'Q'}; );
    ASSERT_ANY_THROW( Symbol{'V'}; );
}

TEST(Symbol, increment) {
    Symbol s{'B'};
    s.increment();
    ASSERT_EQ(s.get(), 'C');
}

TEST(Symbol, skip_D) {
    Symbol s{'C'};
    s.increment();
    ASSERT_EQ(s.get(), 'E');
}

TEST(Symbol, skip_F_G) {
    Symbol s{'E'};
    s.increment();
    ASSERT_EQ(s.get(), 'H');
}

TEST(Symbol, excluded_J) {
    Symbol s{'I'};
    s.increment();
    ASSERT_EQ(s.get(), 'K');
}

TEST(Symbol, excluded_M) {
    Symbol s{'L'};
    s.increment();
    ASSERT_EQ(s.get(), 'N');
}

TEST(Symbol, excluded_Q) {
    Symbol s{'P'};
    s.increment();
    ASSERT_EQ(s.get(), 'R');
}

TEST(Symbol, excluded_V) {
    Symbol s{'U'};
    s.increment();
    ASSERT_EQ(s.get(), 'W');
}
