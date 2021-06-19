#include "separate_range.h"
#include <gtest/gtest.h>


TEST(NiceNumbers13, separateRange1) {
    Range range{1, 12};
    std::vector<Range> expected{ {1, 4}, {5, 8}, {9, 12} };
    std::vector<Range> result = separateRange(range, 3);
    ASSERT_EQ(result, expected);
}

TEST(NiceNumbers13, separateRange2) {
    Range range{1, 11};
    std::vector<Range> expected{ {1, 4}, {5, 8}, {9, 11} };
    std::vector<Range> result = separateRange(range, 3);
    ASSERT_EQ(result, expected);
}

TEST(NiceNumbers13, separateRange3) {
    Range range{1, 13};
    std::vector<Range> expected{ {1, 4}, {5, 8}, {9, 13} };
    std::vector<Range> result = separateRange(range, 3);
    ASSERT_EQ(result, expected);
}

TEST(NiceNumbers13, separateRange4) {
    Range range{0, 11};
    std::vector<Range> expected{ {0, 2}, {3, 5}, {6, 8}, {9, 11} };
    std::vector<Range> result = separateRange(range, 4);
    ASSERT_EQ(result, expected);
}

TEST(NiceNumbers13, separateRange5) {
    Range range{0, 10};
    std::vector<Range> expected{ {0, 2}, {3, 5}, {6, 8}, {9, 10} };
    std::vector<Range> result = separateRange(range, 4);
    ASSERT_EQ(result, expected);
}

TEST(NiceNumbers13, separateRange6) {
    Range range{0, 12};
    std::vector<Range> expected{ {0, 2}, {3, 5}, {6, 8}, {9, 12} };
    std::vector<Range> result = separateRange(range, 4);
    ASSERT_EQ(result, expected);
}

TEST(NiceNumbers13, separateRange7) {
    Range range{42, 42};
    std::vector<Range> expected{ {42, 42} };
    std::vector<Range> result = separateRange(range, 4);
    ASSERT_EQ(result, expected);
}

TEST(NiceNumbers13, separateRange8) {
    Range range{0, 0};
    std::vector<Range> expected{ {0, 0} };
    std::vector<Range> result = separateRange(range, 4);
    ASSERT_EQ(result, expected);
}

TEST(NiceNumbers13, separateRange9) {
    Range range{1, 6};
    std::vector<Range> expected{ {1, 2}, {3, 4}, {5, 6} };
    std::vector<Range> result = separateRange(range, 4);
    ASSERT_EQ(result, expected);
}

TEST(NiceNumbers13, separateRange10) {
    Range range{1, 3};
    std::vector<Range> expected{ {1, 1}, {2, 2}, {3, 3} };
    std::vector<Range> result = separateRange(range, 4);
    ASSERT_EQ(result, expected);
}
