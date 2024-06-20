#include <thread>
#include <mutex>
#include <iostream>
#include <chrono>


void two_threads_with_condition() {
    std::mutex mu;
    std::condition_variable cond;      // Shared condition variable, wait, wait_for, wait_until, notify_one, notify_all
    const char *sharedMes = nullptr;   // Shared resource

    auto pingPongFn =                  // thread body (lambda). Print someone else's message
            [&](const char *mes) {
                while (true) {
                    std::unique_lock<std::mutex> lock(mu);// locks the mutex
                    // std::unique_lock<mutex> lock(mu, std::defer_lock); defer the lock the mutex
                    do {
                        cond.wait(lock,
                                  [&]() {     // wait for condition to be true (unlocks while waiting which allows other threads to modify)
                                      return sharedMes != mes; // statement for when to continue
                                  });
                    } while (sharedMes == mes);  // prevents spurious wakeup
                    std::cout << sharedMes << std::endl;
                    sharedMes = mes;
                    lock.unlock();               // no need to have lock on notify
                    cond.notify_all();           // notify all condition has changed
                    std::this_thread::sleep_for(std::chrono::seconds(3));
                }
            };
    sharedMes = "ping";
    std::thread t1(pingPongFn, sharedMes);  // start example with 2 concurrent threads
    std::thread t2(pingPongFn, "pong");
    t1.join();
    t2.join();
}
