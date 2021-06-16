#include "calc.h"
#include <benchmark/benchmark.h>


void BM_calcComp_1(benchmark::State& state) {
    Number sum{{
        Digit{1},   // 1
        Digit{0},   // 2
        Digit{5},   // 3
        Digit{5},   // 4
        Digit{2},   // 5
        Digit{3},   // 6
    }};

    for (auto _ : state) {
        benchmark::DoNotOptimize(bruteforce::calcComp(sum));
    }
}

void BM_calcComp_2(benchmark::State& state) {
    Number sum{{
        Digit{11},  // 1
        Digit{7},   // 2
        Digit{0},   // 3
        Digit{5},   // 4
        Digit{9},   // 5
        Digit{11},  // 6
    }};

    for (auto _ : state) {
        benchmark::DoNotOptimize(bruteforce::calcComp(sum));
    }
}

BENCHMARK(BM_calcComp_1);
BENCHMARK(BM_calcComp_2);


BENCHMARK_MAIN();
