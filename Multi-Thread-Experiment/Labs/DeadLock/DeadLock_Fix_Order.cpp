#include "DeadLock.h"
#include "Lab.h"
#include <mutex>
#include <thread>
#include <iostream>

static std::mutex m1, m2;

static void SafeOrder() {
    std::lock(m1, m2);
    std::lock_guard<std::mutex> l1(m1, std::adopt_lock);
    std::lock_guard<std::mutex> l2(m2, std::adopt_lock);
}
void Deadlock_Fix_Order() {
    std::thread t1(SafeOrder), t2(SafeOrder);
    t1.join(); t2.join();
    std::cout << "Fixed by lock order\n";
}
REGISTER_LAB("Deadlock:Fix:order", Deadlock_Fix_Order);
