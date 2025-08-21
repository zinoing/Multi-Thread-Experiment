#include "DataRace.h"
#include "Bench.h"
#include "Lab.h"
#include <iostream>
#include <thread>
static int g_raw = 0;

void DataRace_Bug() {
    g_raw = 0;
    auto ms = runThreads(T, [] {
        for (int i = 0; i < N; ++i) g_raw++;
        });
    std::cout << "[Bug] counter=" << g_raw << " / exp=" << (T * N) << " time=" << ms << "ms\n";
}
REGISTER_LAB("DataRace:Bug", DataRace_Bug);
