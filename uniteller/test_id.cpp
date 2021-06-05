#include "id.h"

#include <gtest/gtest.h>


TEST(Id, ctor_empty) {
    ASSERT_ANY_THROW( Id{ std::vector<Item>{} }; );
}

TEST(Id, ctor_overflow) {
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
    ASSERT_ANY_THROW( Id{initValue} );
}

TEST(Id, get) {
    std::vector<Item> initValue = {
        {'A', '9'},
        {'B', '8'},
        {'C', '7'}
    };
    Id id{initValue};
    ASSERT_EQ(id.get(), "C7-B8-A9");
}

TEST(Id, set) {
    std::vector<Item> initValue = {
        {'E', '7'}
    };
    Id id{initValue};

    std::vector<Item> newValue = {
        {'A', '1'},
        {'B', '2'},
        {'C', '3'}
    };
    id.set(newValue);

    ASSERT_EQ(id.get(), "C3-B2-A1");
}

TEST(Id, increment) {
    std::vector<Item> initValue = {
        {'K', '6'}
    };
    Id id{initValue};

    id.increment();
    ASSERT_EQ(id.get(), "K7");
}

TEST(Id, add_group) {
    std::vector<Item> initValue = {
        {'Z', '9'}
    };
    Id id{initValue};

    id.increment();
    ASSERT_EQ(id.get(), "A1-A1");
}

TEST(Id, increment_next_group) {
    std::vector<Item> initValue = {
        {'Z', '9'},
        {'A', '1'}
    };
    Id id{initValue};

    id.increment();
    ASSERT_EQ(id.get(), "A2-A1");
}

TEST(Id, add_group2) {
    std::vector<Item> initValue = {
        {'Z', '9'},
        {'Z', '9'}
    };
    Id id{initValue};

    id.increment();
    ASSERT_EQ(id.get(), "A1-A1-A1");
}

TEST(Id, increment_next_group2) {
    std::vector<Item> initValue = {
        {'Z', '9'},
        {'Z', '9'},
        {'B', '9'}
    };
    Id id{initValue};

    id.increment();
    ASSERT_EQ(id.get(), "C1-A1-A1");
}

TEST(Id, overflow) {
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
    Id id{initValue};

    ASSERT_FALSE(id.increment());
    //                 1  2  3  4  5  6  7  8  9  10
    ASSERT_EQ(id.get(), "Z9-Z9-Z9-Z9-Z9-Z9-Z9-Z9-Z9-Z9");

    ASSERT_TRUE(id.increment());
    ASSERT_EQ(id.get(), "A1");
}
