#include "calc.h"

#include "composition_length.h"
#include "separate_range.h"
#include "parallel_calculation.h"

#include <gtest/gtest.h>

#include <algorithm>


TEST(NiceNumbers13, DISABLED_bruteforce) {
    std::cout << bruteforce::calc() << std::endl;
}


TEST(NiceNumbers13, _) {
    std::vector<Range> ranges = separateRange(Range{0, 12 * 6}, std::thread::hardware_concurrency());

    auto wrapper = [](unsigned int sum) -> std::size_t {
        return bruteforce::compositionLength13(sum, 6);
    };
    std::vector<std::size_t> combs = parallelCalculation(ranges, wrapper);

    auto sumSquare = [](std::size_t sum, std::size_t n) -> std::size_t {
        return sum += n * n;
    };
    std::size_t result = std::accumulate(std::begin(combs), std::end(combs), std::size_t{0});

    std::cout << "Total nice numbers13: " << result << std::endl;
}
