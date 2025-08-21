#include "DataRace.h"
#include "Bench.h"
#include "Lab.h"
#include <mutex>
#include <iostream>
#include <thread>

static int g_m = 0; 
static std::mutex mx;

void DataRace_Fix_Mutex() {
    g_m = 0;
    auto ms = runThreads(T, [] {
        std::lock_guard<std::mutex> lk(mx);
        for (int i = 0; i < N; ++i) { ++g_m; }
        });
    std::cout << "[Fix:Mutex] counter=" << g_m << " time=" << ms << "ms\n";
}
REGISTER_LAB("DataRace:Fix:Mutex", DataRace_Fix_Mutex);
