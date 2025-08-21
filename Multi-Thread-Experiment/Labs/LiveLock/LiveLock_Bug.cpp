#include "Lab.h"
#include "LiveLock.h"
#include <mutex>
#include <thread>
#include <chrono>
#include <iostream>

static std::mutex m1, m2;

static void TryLockA() {
    while (true) {
        if (m1.try_lock()) {
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
            if (m2.try_lock()) {
                m2.unlock(); m1.unlock();
                break;
            }
            else {
                m1.unlock();
                std::this_thread::yield(); 
            }
        }
        else {
            std::this_thread::yield();
        }
    }
}

static void TryLockB() {
    while (true) {
        if (m2.try_lock()) {
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
            if (m1.try_lock()) {
                m1.unlock(); m2.unlock();
                break;
            }
            else {
                m2.unlock();
                std::this_thread::yield();
            }
        }
        else {
            std::this_thread::yield();
        }
    }
}

void Livelock_Bug() {
    std::cout << "Livelock_Bug: program may spin forever. If stuck, Debug > Break All.\n";
    std::thread t1(TryLockA), t2(TryLockB);
    t1.join(); t2.join();
    std::cout << "[Bug] finished\n";
}
REGISTER_LAB("Livelock:Bug", Livelock_Bug);
