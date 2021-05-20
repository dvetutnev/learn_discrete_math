#include <generator.h>
#include <find_sum.h>
#include <benchmark/benchmark.h>

#include <map>


namespace {


struct Data
{
    std::vector<std::size_t> set;
    std::size_t sum;
};


Data generateData(std::size_t size) {
    auto set = generateSet(size);

    auto rnd = getRandomGenerator(1, size);
    std::size_t sum = rnd();

    return Data{std::move(set), sum};
}


const std::map<std::size_t, Data> sets = {
    {10, generateData(10)},
    {100, generateData(100)},
    {1000, generateData(1000)},
    {10000, generateData(10000)}
};


}


void BM_bruteforce(benchmark::State& state) {
    const auto& data = sets.at(state.range(0));
    for (auto _ : state) {
        bruteforce::findPair(data.set, data.sum);
    }
}

BENCHMARK(BM_bruteforce)->Arg(10)->Arg(100)->Arg(1000)->Arg(10000);


void BM_sort(benchmark::State& state) {
    const auto& data = sets.at(state.range(0));
    for (auto _ : state) {
        sort::findPair(data.set, data.sum);
    }
}

BENCHMARK(BM_sort)->Arg(10)->Arg(100)->Arg(1000)->Arg(10000);


BENCHMARK_MAIN();
