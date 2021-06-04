#include "item.h"

#include <gtest/gtest.h>


TEST(Item, get) {
    Item item{ Symbol{'B'}, Digit{'7'} };
    ASSERT_EQ(item.get(), "B7");
}

TEST(Item, increment) {
    Item item{ Symbol{'C'}, Digit{'8'} };
    ASSERT_FALSE(item.increment());
    ASSERT_EQ(item.get(), "C9");
}

TEST(Item, overflow_digit) {
    Item item{ Symbol{'A'}, Digit{'9'} };
    ASSERT_FALSE(item.increment());
    ASSERT_EQ(item.get(), "B1");
}

TEST(Item, overflow_all) {
    Item item{ Symbol{'Z'}, Digit{'9'} };
    ASSERT_TRUE(item.increment());
    ASSERT_EQ(item.get(), "A1");
}
