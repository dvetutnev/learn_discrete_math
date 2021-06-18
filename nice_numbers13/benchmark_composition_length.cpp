#include "composition_length.h"
#include <benchmark/benchmark.h>


void BM_compositionLength13(benchmark::State& state) {
    auto digits = static_cast<unsigned char>(state.range(0));
    for (auto _ : state) {
        benchmark::DoNotOptimize(bruteforce::compositionLength13(42, digits));
    }
}

BENCHMARK(BM_compositionLength13)->Arg(2)->Arg(3)->Arg(4)->Arg(5)->Arg(6);

BENCHMARK_MAIN();
