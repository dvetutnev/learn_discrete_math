#include "number.h"

#include <list>
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

TEST(NiceNumbers13_Number, equal) {
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

TEST(NiceNumbers13_Number, equalDefaultValue) {
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

TEST(NiceNumbers13_Number, less1) {
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

TEST(NiceNumbers13_Number, less2) {
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


TEST(NiceNumbers13_Number, add) {
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

TEST(NiceNumbers13_Number, add_carry) {
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

TEST(NiceNumbers13_Number, add_carry2) {
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

TEST(NiceNumbers13_Number, add_overflow) {
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


TEST(NiceNumbers13_isNice, yes) {
    Number n{{
        Digit{0},   // 1
        Digit{0},   // 2
        Digit{5},   // 3
        Digit{5},   // 4
        Digit{2},   // 5
        Digit{3},   // 6
        Digit{7},   // 7
        Digit{0},   // 8
        Digit{5},   // 9
        Digit{0},   // 10
        Digit{10},  // 11
        Digit{0},   // 12
        Digit{0},   // 13
    }};

    ASSERT_TRUE(isNice(n));
}

TEST(NiceNumbers13_isNice, no) {
    Number n{{
        Digit{1},   // 1
        Digit{2},   // 2
        Digit{3},   // 3
        Digit{4},   // 4
        Digit{10},  // 5
        Digit{11},  // 6
        Digit{9},   // 7
        Digit{8},   // 8
        Digit{8},   // 9
        Digit{11},  // 10
        Digit{10},  // 11
        Digit{11},  // 12
        Digit{10},  // 13
    }};

    ASSERT_FALSE(isNice(n));
}


TEST(NiceNumbers13_number, ctorFromItRange_list) {
    std::list<Digit> l{
        Digit{8},
        Digit{12},
        Digit{0},
        Digit{1}
    };

    Number expected{
        Digit{8},
        Digit{12},
        Digit{0},
        Digit{1}
    };

    Number result{std::begin(l), std::end(l)};
    ASSERT_EQ(result, expected);
}
