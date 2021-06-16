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


TEST(NiceNumbers13_Number, ctor_leadingZero) {
    Number a{{
        Digit{0},
        Digit{0},
        Digit{0},
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

    ASSERT_EQ(a, b);
};


TEST(NiceNumber13_Number, add) {
    Number a{{
        Digit{1},
        Digit{7},
        Digit{2},
        Digit{9},
        Digit{1},
        Digit{1},
        Digit{1},
        Digit{1},
        Digit{1},
        Digit{1},
        Digit{1},
        Digit{1},
        Digit{2},
    }};

    Number expected{{
        Digit{1},
        Digit{7},
        Digit{2},
        Digit{9},
        Digit{1},
        Digit{1},
        Digit{1},
        Digit{1},
        Digit{1},
        Digit{1},
        Digit{1},
        Digit{1},
        Digit{7},
    }};

    Number result = a + Digit{5};
    ASSERT_EQ(result, expected);
}

TEST(NiceNumber13_Number, add_carry) {
    Number a{{
        Digit{1},
        Digit{7},
        Digit{2},
        Digit{9},
        Digit{1},
        Digit{1},
        Digit{1},
        Digit{1},
        Digit{1},
        Digit{1},
        Digit{1},
        Digit{1},
        Digit{11},
    }};

    Number expected{{
        Digit{1},
        Digit{7},
        Digit{2},
        Digit{9},
        Digit{1},
        Digit{1},
        Digit{1},
        Digit{1},
        Digit{1},
        Digit{1},
        Digit{1},
        Digit{2},
        Digit{4},
    }};

    Number result = a + Digit{5};
    ASSERT_EQ(result, expected);
}

TEST(NiceNumber13_Number, add_carry2) {
    Number a{{
        Digit{1},
        Digit{7},
        Digit{2},
        Digit{9},
        Digit{1},
        Digit{1},
        Digit{1},
        Digit{1},
        Digit{1},
        Digit{1},
        Digit{12},
        Digit{12},
        Digit{11},
    }};

    Number expected{{
        Digit{1},
        Digit{7},
        Digit{2},
        Digit{9},
        Digit{1},
        Digit{1},
        Digit{1},
        Digit{1},
        Digit{1},
        Digit{2},
        Digit{1},
        Digit{1},
        Digit{6},
    }};

    Number result = a + Digit{7};
    ASSERT_EQ(result, expected);
}

TEST(NiceNumber13_Number, add_overflow) {
    Number a{{
        Digit{12},  // 1
        Digit{12},  // 2
        Digit{12},  // 3
        Digit{12},  // 4
        Digit{12},  // 5
        Digit{12},  // 6
        Digit{12},  // 7
        Digit{12},  // 8
        Digit{12},  // 9
        Digit{12},  // 10
        Digit{12},  // 11
        Digit{12},  // 12
        Digit{12},  // 13
    }};

    ASSERT_ANY_THROW(a + Digit{6});
}
