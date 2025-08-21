#include "Lab.h"
#include "LiveLock.h"
#include <mutex>
#include <thread>
#include <chrono>
#include <iostream>
#include <random>

static std::mutex m1, m2;

static void backoff(int& delay_us) {
    static thread_local std::mt19937 rng{ std::random_device{}() };
    std::uniform_int_distribution<int> jitter(0, delay_us);
    std::this_thread::sleep_for(std::chrono::microseconds(jitter(rng)));
    delay_us = std::min(delay_us * 2, 2000);
}

static void SafeTryLockA() {
    int delay = 50;
    while (true) {
        if (m1.try_lock()) {
            if (m2.try_lock()) {
                m2.unlock(); m1.unlock();
                break;
            }
            else {
                m1.unlock();
                backoff(delay);
            }
        }
        else {
            backoff(delay);
        }
    }
}

static void SafeTryLockB() {
    int delay = 50;
    while (true) {
        if (m2.try_lock()) {
            if (m1.try_lock()) {
                m1.unlock(); m2.unlock();
                break;
            }
            else {
                m2.unlock();
                backoff(delay);
            }
        }
        else {
            backoff(delay);
        }
    }
}

void Livelock_Fix_Backoff() {
    std::thread t1(SafeTryLockA), t2(SafeTryLockB);
    t1.join(); t2.join();
    std::cout << "[Fix:Backoff] finished\n";
}
REGISTER_LAB("Livelock:Fix:Backoff", Livelock_Fix_Backoff);
