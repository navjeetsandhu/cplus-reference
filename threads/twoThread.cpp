#include <thread>
#include <mutex>
#include <iostream>
#include <chrono>

std::mutex mu;    // mutex
std::condition_variable cond;      // Shared condition variable, wait, wait_for, wait_until, notify_one, notify_all
int shared_value = 0;   // Shared resource


void thread_one(std::string&& name, int value) {
    std::cout << "starting thread " << name << std::endl;
    std::unique_lock<std::mutex> lock(mu);

    
    std::cout << "waiting thread "  << name << " or condition " << std::endl;

    cond.wait(lock, [value]{ return shared_value == value; });


    std::cout << "waiting ended for thread "  << name << " for condition" << std::endl;

    std::cout << "Finishing thread "  << name  << std::endl;

}


void two_threads_with_condition() {

    std::thread t1(thread_one, "thread_one", 1);  // start example with 2 concurrent threads
    std::thread t2(thread_one, "thread_two", 2);
    std::this_thread::sleep_for(std::chrono::seconds(4));
    std::cout << "Created two threads" << std::endl;


    std::this_thread::sleep_for(std::chrono::seconds(4));

    std::cout << "setting condition one" << std::endl;
    shared_value = 1;
    cond.notify_all();

    std::this_thread::sleep_for(std::chrono::seconds(4));


    std::cout << "setting condition two" << std::endl;
    shared_value = 2;
    cond.notify_all();

    std::this_thread::sleep_for(std::chrono::seconds(4));



    std::cout << "Joining two threads" << std::endl;

    t1.join();
    t2.join();
    std::this_thread::sleep_for(std::chrono::seconds(4));
    std::cout << "Finishing main thread" << std::endl;
}

