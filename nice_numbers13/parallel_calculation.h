#pragma once

#include <thread>
#include <future>
#include <functional>
#include <vector>


using Range = std::pair<unsigned int, unsigned int>;
using Operation = std::function<std::size_t(unsigned int)>;

struct Thread
{
    std::thread thread;
    std::future<std::size_t> future;
};

inline std::vector<std::size_t> parallelCalculation(std::vector<Range>, Operation);
