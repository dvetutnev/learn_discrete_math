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
