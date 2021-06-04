#include "item.h"

#include <gtest/gtest.h>


TEST(Item, get) {
    Item item{ Symbol{'B'}, Digit{'7'} };
    ASSERT_EQ(item.get(), "B7");
}
