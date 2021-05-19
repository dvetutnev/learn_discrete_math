#include "generator.h"
#include <gtest/gtest.h>


TEST(find_sum_generator, random_generator) {
    auto gen = getRandomGenerator(1, 99);

    unsigned a = gen();
    unsigned b = gen();

    ASSERT_GE(a, 1);
    ASSERT_LE(a, 99);
    ASSERT_GE(b, 1);
    ASSERT_LE(b, 99);

    std::cout << "a: " << a << " b: " << b << std::endl;
}
