#include "composition_length.h"
#include <gtest/gtest.h>


TEST(compositionLength, happyTickets6) {
    std::size_t result = 0;
    for (unsigned int k = 0; k <= 9*3; k++) {
        std::size_t l = compositionLength(k, 3);
        result += l * l;
    }
    ASSERT_EQ(result, 55252);
}


TEST(compositionLength, DISABLED_bruteforce20_3) {
    std::size_t lb = bruteforce::compositionLength13(20, 3);
    std::size_t l = compositionLength(20, 3, 13);
    ASSERT_EQ(lb, l);
}

TEST(compositionLength, DISABLED_bruteforce20_2) {
    std::size_t lb = bruteforce::compositionLength13(20, 2);
    std::size_t l = compositionLength(20, 2, 13);
    ASSERT_EQ(lb, l);
}


TEST(compositionLength, bruteforce22_2) {
    std::size_t lb = bruteforce::compositionLength13(22, 2);
    ASSERT_EQ(lb, 3);
}

TEST(compositionLength, bruteforce14_2) {
    std::size_t lb = bruteforce::compositionLength13(14, 2);
    ASSERT_EQ(lb, 11);
}

TEST(compositionLength, bruteforce34_3) {
    std::size_t lb = bruteforce::compositionLength13(34, 3);
    ASSERT_EQ(lb, 6);
}

TEST(compositionLength, bruteforce33_3) {
    std::size_t lb = bruteforce::compositionLength13(33, 3);
    ASSERT_EQ(lb, 10);
}

TEST(compositionLength, bruteforce48_4) {
    std::size_t lb = bruteforce::compositionLength13(48, 4);
    ASSERT_EQ(lb, 1);
}

TEST(compositionLength, bruteforce84_7) {
    std::size_t lb = bruteforce::compositionLength13(84, 7);
    ASSERT_EQ(lb, 1);
}

