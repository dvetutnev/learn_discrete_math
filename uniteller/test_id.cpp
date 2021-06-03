#include <gtest/gtest.h>

#include <vector>
#include <algorithm>
#include <stdexcept>


class Symbol
{
public:
    Symbol(char);

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
