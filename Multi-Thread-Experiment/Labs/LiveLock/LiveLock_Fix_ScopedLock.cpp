#include "Lab.h"
#include "LiveLock.h"
#include <mutex>
#include <thread>
#include <iostream>

static std::mutex m1, m2;

static void SafeBoth() {
    std::scoped_lock lk(m1, m2);
}

void Livelock_Fix_ScopedLock() {
    std::thread t1(SafeBoth), t2(SafeBoth);
    t1.join(); t2.join();
    std::cout << "[Fix:ScopedLock] finished\n";
}
REGISTER_LAB("Livelock:Fix:ScopedLock", Livelock_Fix_ScopedLock);
