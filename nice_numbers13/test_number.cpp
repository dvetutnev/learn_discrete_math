#include "number.h"
#include <gtest/gtest.h>


TEST(NiceNumbers13_Number, ctor) {
    Number a{{
        Digit{12},
        Digit{11},
        Digit{10},
        Digit{9},
        Digit{8},
        Digit{7},
        Digit{6},
        Digit{5},
        Digit{4},
        Digit{3},
        Digit{2},
        Digit{1},
        Digit{0},
    }};

    Number b{};
}

TEST(NiceNumber13_Number, equal) {
    Number a{{
        Digit{12},
        Digit{11},
        Digit{10},
        Digit{9},
        Digit{8},
        Digit{7},
        Digit{6},
        Digit{5},
        Digit{4},
        Digit{3},
        Digit{2},
        Digit{1},
        Digit{0},
    }};

    Number b{{
        Digit{12},
        Digit{11},
        Digit{10},
        Digit{9},
        Digit{8},
        Digit{7},
        Digit{6},
        Digit{5},
        Digit{4},
        Digit{3},
        Digit{2},
        Digit{1},
        Digit{0},
    }};

    Number c{{
        Digit{12},
        Digit{11},
        Digit{10},
        Digit{9},
        Digit{8},
        Digit{7},
        Digit{0},
        Digit{0},
        Digit{4},
        Digit{3},
        Digit{2},
        Digit{1},
        Digit{0},
    }};

    EXPECT_EQ(a, b);
    EXPECT_NE(b, c);
}

TEST(NiceNumber13_Number, equalDefaultValue) {
    Number a{{
        Digit{0},
        Digit{0},
        Digit{0},
        Digit{0},
        Digit{0},
        Digit{0},
        Digit{0},
        Digit{0},
        Digit{0},
        Digit{0},
        Digit{0},
        Digit{0},
        Digit{0},
    }};

    Number b{};

    EXPECT_EQ(a, b);
}

TEST(NiceNumber13_Number, less1) {
    Number a{{
        Digit{1},
        Digit{1},
        Digit{1},
        Digit{1},
        Digit{1},
        Digit{1},
        Digit{1},
        Digit{1},
        Digit{1},
        Digit{1},
        Digit{1},
        Digit{1},
        Digit{0},
    }};

    Number b{{
        Digit{1},
        Digit{1},
        Digit{1},
        Digit{1},
        Digit{1},
        Digit{1},
        Digit{1},
        Digit{1},
        Digit{1},
        Digit{1},
        Digit{1},
        Digit{1},
        Digit{1},
    }};

    Number c{{
        Digit{1},
        Digit{1},
        Digit{1},
        Digit{1},
        Digit{1},
        Digit{1},
        Digit{1},
        Digit{1},
        Digit{1},
        Digit{1},
        Digit{1},
        Digit{1},
        Digit{1},
    }};

    EXPECT_TRUE(a < b);
    EXPECT_FALSE(b < c);
}

TEST(NiceNumber13_Number, less2) {
    Number a{{
        Digit{1},
        Digit{1},
        Digit{2},
        Digit{1},
        Digit{1},
        Digit{1},
        Digit{1},
        Digit{1},
        Digit{1},
        Digit{1},
        Digit{1},
        Digit{1},
        Digit{0},
    }};

    Number b{{
        Digit{1},
        Digit{1},
        Digit{3},
        Digit{1},
        Digit{1},
        Digit{1},
        Digit{1},
        Digit{1},
        Digit{1},
        Digit{1},
        Digit{1},
        Digit{1},
        Digit{1},
    }};

    Number c{{
        Digit{1},
        Digit{2},
        Digit{1},
        Digit{1},
        Digit{1},
        Digit{1},
        Digit{1},
        Digit{1},
        Digit{1},
        Digit{1},
        Digit{1},
        Digit{1},
        Digit{1},
    }};

    EXPECT_TRUE(a < b);
    EXPECT_TRUE(b < c);
}
