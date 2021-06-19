#pragma once

#include <thread>
#include <condition_variable>
#include <functional>
#include <vector>
#include <algorithm>
#include <memory>


using Range = std::pair<unsigned int, unsigned int>;
using Operation = std::function<std::size_t(unsigned int)>;

struct Thread
{
    std::thread thread;
    std::shared_ptr<std::vector<std::size_t>> result;
};

inline std::vector<std::size_t> parallelCalculation(const std::vector<Range>& ranges, Operation operation) {
    std::size_t inProgres = ranges.size();
    std::mutex mutex;
    std::condition_variable cv;

    auto signal = [&inProgres, &mutex, &cv] () {
        {
            std::unique_lock<std::mutex> lock{mutex};
            inProgres--;
        }
        cv.notify_one();
    };

    auto waitThreads = [&inProgres, &mutex, &cv] () {
        std::unique_lock lock{mutex};
        auto pred = [&inProgres] () {
            return inProgres == 0;
        };
        cv.wait(lock, pred);
    };

    auto makeThread = [operation, &signal] (Range range) -> Thread {
        auto result = std::make_shared<std::vector<std::size_t>>();

        auto worker = [range, operation, result, &signal] () {
            for (auto i = range.first; i <= range.second; i++) {
                result->push_back(operation(i));
            }
            signal();
        };

        return Thread{ std::thread{std::move(worker)}, std::move(result) };
    };

    std::vector<Thread> threads;
    for (const auto& range : ranges) {
        threads.push_back(makeThread(range));
    }

    waitThreads();

    std::vector<std::size_t> result;
    for (Thread& t : threads) {
        t.thread.join();
        std::copy(t.result->begin(), t.result->end(), std::back_inserter(result));
    }

    return result;
}
