#pragma once
#include <chrono>
#include <thread>
#include <vector>

template <class F>
long long runThreads(int T, F f) {
    auto st = std::chrono::high_resolution_clock::now();
    std::vector<std::thread> v; v.reserve(T);
    for (int i = 0; i < T; ++i) v.emplace_back(f);
    for (auto& t : v) t.join();
    auto ed = std::chrono::high_resolution_clock::now();
    return std::chrono::duration_cast<std::chrono::milliseconds>(ed - st).count();
}
