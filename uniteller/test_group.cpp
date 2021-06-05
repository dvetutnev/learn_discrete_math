#include "group.h"

#include <gtest/gtest.h>


TEST(Group, get) {
    Group g{ Symbol{'B'}, Digit{'7'} };
    ASSERT_EQ(g.get(), "B7");
}

TEST(Group, increment) {
    Group g{ Symbol{'C'}, Digit{'8'} };
    ASSERT_FALSE(g.increment());
    ASSERT_EQ(g.get(), "C9");
}

TEST(Group, overflow_digit) {
    Group g{ Symbol{'A'}, Digit{'9'} };
    ASSERT_FALSE(g.increment());
    ASSERT_EQ(g.get(), "B1");
}

TEST(Group, overflow_all) {
    Group g{ Symbol{'Z'}, Digit{'9'} };
    ASSERT_TRUE(g.increment());
    ASSERT_EQ(g.get(), "A1");
}
