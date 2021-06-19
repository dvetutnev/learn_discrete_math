#include "parallel_calculation.h"
#include <gmock/gmock.h>

#include <mutex>

using ::testing::Return;


struct MockCompositionLength
{
    MOCK_METHOD(std::size_t, call, (unsigned int), ());
};


TEST(parallelCalculationLength, _) {
    const std::vector<Range> ranges{ {7, 9}, {10, 12} };

    MockCompositionLength mock;

    EXPECT_CALL(mock, call(7)).WillOnce(Return(14));
    EXPECT_CALL(mock, call(8)).WillOnce(Return(16));
    EXPECT_CALL(mock, call(9)).WillOnce(Return(18));

    EXPECT_CALL(mock, call(10)).WillOnce(Return(20));
    EXPECT_CALL(mock, call(11)).WillOnce(Return(22));
    EXPECT_CALL(mock, call(12)).WillOnce(Return(24));

    const std::vector<std::size_t> expected{14, 16, 18, 20, 22, 24};

    auto wrapper = [&mock](unsigned int k) -> std::size_t {
        static std::mutex mtx;
        std::lock_guard lock{mtx};
        return mock.call(k);
    };
    const std::vector<std::size_t> result = parallelCalculation(ranges, wrapper);

    ASSERT_EQ(result, expected);
};
