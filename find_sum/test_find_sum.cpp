#include "find_sum.h"
#include <gtest/gtest.h>


TEST(find_sum, bruteforce1) {
    std::vector<std::size_t> set = {3, 1, 2};
    std::size_t sum = 3;
    std::pair<std::size_t, std::size_t> pair = {1, 2};

    auto result = bruteforce::findPair(set, sum);

    ASSERT_TRUE(result);
    ASSERT_EQ(*result, pair);
}

TEST(find_sum, bruteforce2) {
    std::vector<std::size_t> set = {4, 6, 5};
    std::size_t sum = 6;

    auto result = bruteforce::findPair(set, sum);

    ASSERT_FALSE(result);
}

TEST(find_sum, bruteforce3) {
    std::vector<std::size_t> set = {3};
    std::size_t sum = 6;

    auto result = bruteforce::findPair(set, sum);

    ASSERT_FALSE(result);
}

TEST(find_sum, bruteforce4) {
    std::vector<std::size_t> set = {4, 5, 1, 3};
    std::size_t sum = 8;
    std::pair<std::size_t, std::size_t> pair = {5, 3};

    auto result = bruteforce::findPair(set, sum);

    ASSERT_TRUE(result);
    ASSERT_EQ(*result, pair);
}
