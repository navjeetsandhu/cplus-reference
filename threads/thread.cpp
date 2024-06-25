#include <thread>
#include <mutex>
#include <iostream>

void ping_pong_threads() {
    std::mutex mu;
    std::condition_variable cond;      // Shared condition variable, wait, wait_for, wait_until, notify_one, notify_all
    const char *sharedMes = nullptr;   // Shared resource

    unsigned int n = std::thread::hardware_concurrency();
    std::cout << "hardware concurrency" << ' ' << n << "\n";


    auto pingPongFn =                  // thread body (lambda). Print someone else's message
            [&](const char *mes) {
                for (int i=0;i<7;i++) {
                    std::unique_lock<std::mutex> lock(mu);// locks the mutex
                    auto conditionWaitFn = [&]() {return sharedMes != mes; };
                    do {
                        cond.wait(lock,conditionWaitFn);
                    } while (sharedMes == mes);  // prevents spurious wakeup
                    std::cout << i << "  " << sharedMes << std::endl;
                    sharedMes = mes;
                    lock.unlock();
                    cond.notify_all();           // notify all condition has changed
                }
            };
    sharedMes = "ping";
    std::thread t1(pingPongFn, sharedMes);  // start example with 2 concurrent threads
    std::thread t2(pingPongFn, "pong");
    t1.join();
    t2.join();
}
