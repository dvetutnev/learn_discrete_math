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

TEST(Group, increment) {
    std::vector<Item> initValue = {
        {'K', '6'}
    };
    Group g{initValue};

    g.increment();
    ASSERT_EQ(g.get(), "K7");
}

TEST(Group, overflow_item) {
    std::vector<Item> initValue = {
        {'Z', '9'}
    };
    Group g{initValue};

    g.increment();
    ASSERT_EQ(g.get(), "A1-A1");
}

TEST(Group, overflow_item2) {
    std::vector<Item> initValue = {
        {'Z', '9'},
        {'A', '1'}
    };
    Group g{initValue};

    g.increment();
    ASSERT_EQ(g.get(), "A2-A1");
}

TEST(Group, overflow_several_items) {
    std::vector<Item> initValue = {
        {'Z', '9'},
        {'Z', '9'}
    };
    Group g{initValue};

    g.increment();
    ASSERT_EQ(g.get(), "A1-A1-A1");
}

TEST(Group, overflow_several_items2) {
    std::vector<Item> initValue = {
        {'Z', '9'},
        {'Z', '9'},
        {'B', '9'}
    };
    Group g{initValue};

    g.increment();
    ASSERT_EQ(g.get(), "C1-A1-A1");
}

TEST(Group, overflow_all) {
    std::vector<Item> initValue = {
        {'Z', '8'}, // 1
        {'Z', '9'}, // 2
        {'Z', '9'}, // 3
        {'Z', '9'}, // 4
        {'Z', '9'}, // 5
        {'Z', '9'}, // 6
        {'Z', '9'}, // 7
        {'Z', '9'}, // 8
        {'Z', '9'}, // 9
        {'Z', '9'}, // 10
    };
    Group g{initValue};

    ASSERT_FALSE(g.increment());
    //                 1  2  3  4  5  6  7  8  9  10
    ASSERT_EQ(g.get(), "Z9-Z9-Z9-Z9-Z9-Z9-Z9-Z9-Z9-Z9");

    ASSERT_TRUE(g.increment());
    ASSERT_EQ(g.get(), "A1");
}
