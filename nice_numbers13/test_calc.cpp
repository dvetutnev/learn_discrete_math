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


std::size_t D(std::size_t n, std::size_t k) {
    if (n == 0) {
        return (k == 0) ? 1 : 0;
    }
    else {
        std::size_t c = 0;
        for (std::size_t j = 0; j < 13 && j <= k; j++) {
            c += D(n - 1, k - j);
        }
        return c;
    }
}

TEST(NiceNumbers13, D_63) {
    std::size_t res = D(6, 63);
    ASSERT_NE(res, 0);
    std::cout << "D(6, 63): " << res << std::endl;
}

TEST(NiceNumbers13, D_9) {
    std::size_t res = D(6, 9);
    ASSERT_NE(res, 0);
    std::cout << "D(6, 9): " << res << std::endl;
}

TEST(NiceNumbers13, D_19) {
    std::size_t res = D(6, 19);
    ASSERT_NE(res, 0);
    std::cout << "D(6, 19): " << res << std::endl;
}

TEST(NiceNumbers13, D_279) {
    std::size_t res = D(6, 279);
    ASSERT_EQ(res, 0);
}

TEST(NiceNumbers13, D_72) {
    std::size_t res = D(6, 72);
    ASSERT_EQ(res, 1);
}

TEST(NiceNumbers13, D_71) {
    std::size_t res = D(6, 71);
    ASSERT_EQ(res, 6);
}


std::size_t calcNiceNumbers13() {
    const std::size_t digits = 6;
    const std::size_t maxSum = 12 * 6;
    std::size_t res = 0;

    for (std::size_t s = 0; s <= maxSum; s++) {
        std::size_t N = D(digits, s);
        res += N *N;
    }

    return res;
}

TEST(calcNiceNumbers13, 0) {
    std::size_t res = calcNiceNumbers13();
    ASSERT_NE(res, 0);
    std::cout << "calcNiceNumbers13(): " << res << std::endl;
}
