#include "symbol.h"

#include <gtest/gtest.h>


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


TEST(Symbol, overflow) {
    Symbol s{'Y'};

    ASSERT_FALSE(s.increment());
    ASSERT_EQ(s.get(), 'Z');

    ASSERT_TRUE(s.increment());
    ASSERT_EQ(s.get(), 'A');
}
