#include <iostream>
#include <semaphore>
#include <thread>
#include <atomic>


std::binary_semaphore signalToThread{0};

void InterruptHandler() {
    signalToThread.release();
}

[[noreturn]] void periodicInterruptSimulate() {
    while (true) {
        InterruptHandler();
        using namespace std::literals;
        std::this_thread::sleep_for(3s);
    }
}


[[noreturn]] void ThreadProcSignal()
{
    while (true) {
        signalToThread.acquire();
        std::cout << "[thread] Got the signal\n"; // response message
        using namespace std::literals;
    }
}

void interruptSemaphoreExample()
{
    // create some worker thread
    std::thread t1(ThreadProcSignal);

    std::thread t2(periodicInterruptSimulate);


    std::cout << "[main] Send the signal\n"; // message


    signalToThread.release();


    t1.join();
    t2.join();
}