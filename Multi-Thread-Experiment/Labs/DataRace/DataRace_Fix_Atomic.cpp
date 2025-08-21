#include "DataRace.h"
#include "Bench.h"
#include "Lab.h"
#include <atomic>
#include <iostream>
#include <thread>

static std::atomic<int> g_a{ 0 };

void DataRace_Fix_Atomic() {
    g_a.store(0);
    auto ms = runThreads(T, [] {
        for (int i = 0; i < N; ++i) g_a.fetch_add(1, std::memory_order_relaxed);
        });
    std::cout << "[Fix:Atomic] counter=" << g_a.load() << " time=" << ms << "ms\n";
}
REGISTER_LAB("DataRace:Fix:Atomic", DataRace_Fix_Atomic);
