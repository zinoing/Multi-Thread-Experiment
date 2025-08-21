#include "DeadLock.h"
#include "Lab.h"
#include <mutex>
#include <thread>
#include <iostream>

static std::mutex m1, m2;

static void Safe() {
    std::scoped_lock lk(m1, m2);
    (void)lk;
}
void Deadlock_Fix_ScopedLock() {
    std::thread t1(Safe), t2(Safe);
    t1.join(); t2.join();
    std::cout << "Fixed by scoped_lock\n";
}
REGISTER_LAB("Deadlock:Fix:scoped_lock", Deadlock_Fix_ScopedLock);
