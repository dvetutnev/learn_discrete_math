#include "boats.h"
#include <gtest/gtest.h>


// Есть матрица NxN, состоящая из 0 и 1, и отражающая расположения кораблей на поле для морского боя.

// Поле может быть любого размера, но обязательно квадратное.
// Кораблей может быть любое количество
// Размер кораблей — от 1х1 до 1хN
// Корабли никак не соприкасаются друг с другом.
// Могут располагаться горизонтально и вертикально
// Необходимо подсчитать количество кораблей.

TEST(boats, a) {
    Matrix matrix = {
        {4, 0, 0, 0},
        {4, 0, 2, 2},
        {4, 0, 0, 0},
        {4, 0, 0, 1}
    };

    std::size_t result = calcBoats(matrix);
    ASSERT_EQ(result, 3);
}

TEST(boats, b) {
    Matrix matrix = {
        {0, 4, 0, 0},
        {0, 4, 0, 1},
        {0, 4, 0, 0},
        {0, 4, 0, 1}
    };

    std::size_t result = calcBoats(matrix);
    ASSERT_EQ(result, 3);
}

TEST(boats, c) {
    Matrix matrix = {
        {3, 0, 0, 4},
        {3, 0, 0, 4},
        {3, 0, 0, 4},
        {0, 0, 0, 4}
    };

    std::size_t result = calcBoats(matrix);
    ASSERT_EQ(result, 2);
}

TEST(boats, d) {
    Matrix matrix = {
        {2, 0, 0, 4},
        {2, 0, 0, 4},
        {0, 0, 0, 4},
        {1, 0, 0, 4}
    };

    std::size_t result = calcBoats(matrix);
    ASSERT_EQ(result, 3);
}

TEST(boats, e) {
    Matrix matrix = {
        {2, 0, 0, 4},
        {2, 0, 0, 4},
        {0, 1, 0, 4},
        {0, 0, 0, 4}
    };

    std::size_t result = calcBoats(matrix);
    ASSERT_EQ(result, 3);
}

TEST(boats, f) {
    Matrix matrix = {
        {2, 0, 0, 4},
        {2, 0, 0, 4},
        {0, 1, 0, 4},
        {1, 0, 0, 4}
    };

    std::size_t result = calcBoats(matrix);
    ASSERT_EQ(result, 4);
}

TEST(boats, g) {
    Matrix matrix = {
        {4, 4, 4, 4},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 3, 3, 3}
    };

    std::size_t result = calcBoats(matrix);
    ASSERT_EQ(result, 2);
}

TEST(boats, h) {
    Matrix matrix = {
        {3, 3, 3, 0},
        {0, 0, 0, 1},
        {0, 0, 0, 0},
        {4, 4, 4, 4}
    };

    std::size_t result = calcBoats(matrix);
    ASSERT_EQ(result, 3);
}
