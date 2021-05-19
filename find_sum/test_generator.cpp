#include "generator.h"

#include <gtest/gtest.h>
#include <pprint.hpp>


TEST(find_sum_generator, randomGenerator) {
    auto gen = getRandomGenerator(1, 99);

    unsigned a = gen();
    unsigned b = gen();

    ASSERT_GE(a, 1);
    ASSERT_LE(a, 99);
    ASSERT_GE(b, 1);
    ASSERT_LE(b, 99);

    std::cout << "a: " << a << " b: " << b << std::endl;
}


TEST(find_sum_generator, generateSet) {
    auto set = generateSet(117);
    pprint::PrettyPrinter printer;
    printer.print(set);
}
