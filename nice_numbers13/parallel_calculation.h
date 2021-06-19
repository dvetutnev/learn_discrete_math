#pragma once

#include <thread>
#include <future>
#include <functional>
#include <vector>
#include <algorithm>


using Range = std::pair<unsigned int, unsigned int>;
using Operation = std::function<std::size_t(unsigned int)>;

struct Thread
{
    std::thread thread;
    std::future<std::vector<std::size_t>> future;
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
        std::promise<std::vector<std::size_t>> promise;
        auto future = promise.get_future();

        auto worker = [range, operation, promise = std::move(promise), &signal] () mutable {
            std::vector<std::size_t> result;

            for (auto i = range.first; i <= range.second; i++) {
                result.push_back(operation(i));
            }

            promise.set_value(std::move(result));
            signal();
        };

        return Thread{ std::thread{std::move(worker)}, std::move(future) };
    };

    std::vector<Thread> threads;
    for (const auto& range : ranges) {
        threads.push_back(makeThread(range));
    }

    waitThreads();

    std::vector<std::size_t> result;
    for (Thread& t : threads) {
        t.thread.join();
        std::vector<std::size_t> chunk = t.future.get();
        std::copy(std::begin(chunk), std::end(chunk), std::back_inserter(result));
    }

    return result;
}
