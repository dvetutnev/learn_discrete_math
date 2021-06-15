#include "digit.h"
#include <gtest/gtest.h>


TEST(NiceNumbers13_Digit, ctor) {
    EXPECT_NO_THROW(Digit(0));
    EXPECT_NO_THROW(Digit(7));
    EXPECT_NO_THROW(Digit(12));
    EXPECT_ANY_THROW(Digit(13));
    EXPECT_ANY_THROW(Digit(42));
}

TEST(NiceNumbers13_Digit, equal) {
    EXPECT_EQ(Digit(5), Digit{5});
    EXPECT_NE(Digit(8), Digit{5});
}


TEST(NiceNumbers13_Digit, sum) {
    Digit a{2};
    Digit b{3};

    Digit::Sum result = a + b;

    EXPECT_EQ(result.value, Digit{5});
    EXPECT_EQ(result.carry, Digit{0});
}

TEST(NiceNumbers13_Digit, sum_carry) {
    Digit a{7};
    Digit b{8};

    Digit::Sum result = a + b;

    EXPECT_EQ(result.value, Digit{3});
    EXPECT_EQ(result.carry, Digit{1});
}

TEST(NiceNumbers13_Digit, sum_carry2) {
    Digit a{12};
    Digit b{12};

    Digit::Sum result = a + b;

    EXPECT_EQ(result.value, Digit{12});
    EXPECT_EQ(result.carry, Digit{1});
}
