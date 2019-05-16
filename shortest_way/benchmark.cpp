// Learning discrete mathematics
// Find shortest way
// Dmitriy Vetutnev, 2019


#include "shortest_way.h"

#include <benchmark/benchmark.h>


static const std::vector<Town> towns = generate();
static const DistanceTowns distanceTowns = calcDistanceTowns(towns);


void brutforceBechmark(benchmark::State& state) {
    for (auto _ : state) {
        brutforce(distanceTowns);
    }
}
BENCHMARK(brutforceBechmark);

void primeBechmark(benchmark::State& state) {
    for (auto _ : state) {
        prime(distanceTowns);
    }
}
BENCHMARK(primeBechmark);


BENCHMARK_MAIN();
