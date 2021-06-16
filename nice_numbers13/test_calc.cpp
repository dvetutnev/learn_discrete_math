#include "calc.h"
#include <gtest/gtest.h>


TEST(NiceNumbers13, DISABLED_bruteforce) {
    std::cout << bruteforce::calc() << std::endl;
}


TEST(NiceNumbers13, calcComp) {
    Number sum{{
        Digit{0},   // 1
        Digit{0},   // 2
        Digit{0},   // 3
        Digit{0},   // 4
        Digit{0},   // 5
        Digit{9},   // 6
    }};

    std::size_t compCount = bruteforce::calcComp(sum);
    ASSERT_NE(compCount, 0);
    std::cout << "compCount: " << compCount << std::endl;
}
