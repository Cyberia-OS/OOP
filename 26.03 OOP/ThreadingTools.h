#pragma once

#include <thread>
#include <mutex>
#include <iostream>

using namespace std;

class ThreadGuard {
private:
    thread worker;
public:
    template <typename Callable>
    ThreadGuard(Callable&& task) : worker(forward<Callable>(task)) {
        cout << "[ThreadGuard] Поток запущен" << endl;
    }
    ThreadGuard(const ThreadGuard&) = delete;
    ThreadGuard& operator=(const ThreadGuard&) = delete;
    ~ThreadGuard() {
        if (worker.joinable()) {
            worker.join();
            cout << "[ThreadGuard] Поток завершён (join)" << endl;
        }
    }
};

class AtomicCounter {
private:
    int value;
    mutable mutex mtx;
public:
    AtomicCounter(int initial = 0) : value(initial) {}
    void increment() {
        lock_guard<mutex> lock(mtx);
        ++value;
    }
    void decrement() {
        lock_guard<mutex> lock(mtx);
        --value;
    }
    int get() const {
        lock_guard<mutex> lock(mtx);
        return value;
    }
};
