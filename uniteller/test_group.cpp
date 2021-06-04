#include "group.h"

#include <gtest/gtest.h>


TEST(Group, ctor_empty) {
    ASSERT_ANY_THROW( Group{ std::vector<Item>{} }; );
}

TEST(Group, ctor_overflow) {
    std::vector<Item> initValue = {
        {'A', '1'},
        {'A', '2'},
        {'A', '3'},
        {'A', '4'},
        {'A', '5'},
        {'A', '6'},
        {'A', '7'},
        {'A', '8'},
        {'A', '9'},
        {'B', '1'},
        {'C', '1'},
    };
    ASSERT_ANY_THROW( Group{initValue} );
}

TEST(Group, get) {
    std::vector<Item> initValue = {
        {'A', '9'},
        {'B', '8'},
        {'C', '7'}
    };
    Group g{initValue};
    ASSERT_EQ(g.get(), "C7-B8-A9");
}

TEST(Group, set) {
    std::vector<Item> initValue = {
        {'E', '7'}
    };
    Group g{initValue};

    std::vector<Item> newValue = {
        {'A', '1'},
        {'B', '2'},
        {'C', '3'}
    };
    g.set(newValue);

    ASSERT_EQ(g.get(), "C3-B2-A1");
}
