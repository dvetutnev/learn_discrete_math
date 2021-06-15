#include "digit.h"
#include <gtest/gtest.h>


TEST(Digit, ctor) {
    EXPECT_NO_THROW(Digit(0));
    EXPECT_NO_THROW(Digit(7));
    EXPECT_NO_THROW(Digit(12));
    EXPECT_ANY_THROW(Digit(13));
    EXPECT_ANY_THROW(Digit(42));
}

TEST(Digit, equal) {
    EXPECT_EQ(Digit(5), Digit{5});
    EXPECT_NE(Digit(8), Digit{5});
}
