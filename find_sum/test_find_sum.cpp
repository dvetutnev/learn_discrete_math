#include "find_sum.h"
#include <gtest/gtest.h>


namespace internal {


void sort(std::pair<std::size_t, std::size_t>& p) {
    if (p.first > p.second) {
        std::swap(p.first, p.second);
    }
}


}


TEST(find_sum, bruteforce1) {
    std::vector<std::size_t> set = {3, 1, 2};
    std::size_t sum = 3;
    std::pair<std::size_t, std::size_t> pair = {1, 2};

    auto result = bruteforce::findPair(set, sum);

    ASSERT_TRUE(result);

    internal::sort(pair);
    internal::sort(*result);

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

    internal::sort(pair);
    internal::sort(*result);

    ASSERT_EQ(*result, pair);
}


TEST(find_sum, sort1) {
    std::vector<std::size_t> set = {3, 1, 2};
    std::size_t sum = 3;
    std::pair<std::size_t, std::size_t> pair = {1, 2};

    auto result = sort::findPair(set, sum);

    ASSERT_TRUE(result);

    internal::sort(pair);
    internal::sort(*result);

    ASSERT_EQ(*result, pair);
}

TEST(find_sum, sort2) {
    std::vector<std::size_t> set = {4, 6, 5};
    std::size_t sum = 6;

    auto result = sort::findPair(set, sum);

    ASSERT_FALSE(result);
}

TEST(find_sum, sort3) {
    std::vector<std::size_t> set = {3};
    std::size_t sum = 6;

    auto result = sort::findPair(set, sum);

    ASSERT_FALSE(result);
}

TEST(find_sum, sort4) {
    std::vector<std::size_t> set = {4, 5, 1, 3};
    std::size_t sum = 8;
    std::pair<std::size_t, std::size_t> pair = {5, 3};

    auto result = sort::findPair(set, sum);

    ASSERT_TRUE(result);

    internal::sort(pair);
    internal::sort(*result);

    ASSERT_EQ(*result, pair);
}
