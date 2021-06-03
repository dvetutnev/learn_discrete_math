#include "digit.h"

#include <gtest/gtest.h>


TEST(Digit, ctor) {
    ASSERT_NO_THROW( Digit{'1'}; );

    ASSERT_ANY_THROW( Digit{'0'}; );
    ASSERT_ANY_THROW( Digit{'A'}; );
}

TEST(Digit, increment) {
    Digit d{'8'};

    ASSERT_FALSE(d.increment());
    ASSERT_EQ(d.get(), '9');

    ASSERT_TRUE(d.increment());
    ASSERT_EQ(d.get(), '1');
}
