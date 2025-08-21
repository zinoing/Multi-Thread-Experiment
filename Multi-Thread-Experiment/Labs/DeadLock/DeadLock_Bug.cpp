#include "DeadLock.h"
#include "Lab.h"
#include <mutex>
#include <thread>
#include <chrono>
#include <iostream>

static std::mutex m1, m2;

static void A() { 
    std::lock_guard<std::mutex> l1(m1); 
    std::this_thread::sleep_for(std::chrono::milliseconds(1)); 
    std::lock_guard<std::mutex> l2(m2); 
}

static void B() { 
    std::lock_guard<std::mutex> l2(m2); 
    std::this_thread::sleep_for(std::chrono::milliseconds(1)); 
    std::lock_guard<std::mutex> l1(m1); 
}

void Deadlock_Bug() {
    std::cout << "Deadlock_Bug: program may hang. If stuck, Debug > Break All.\n";
    std::thread t1(A), t2(B);
    t1.join(); t2.join();
}
REGISTER_LAB("Deadlock:Bug", Deadlock_Bug);
