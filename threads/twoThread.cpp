#include <thread>
#include <mutex>
#include <iostream>
#include <chrono>

std::mutex mu;    // mutex
std::condition_variable cond;      // Shared condition variable, wait, wait_for, wait_until, notify_one, notify_all
int shared_value = 0;   // Shared resource



void thread_one() {
    std::cout << "starting thread one" << std::endl;
    std::unique_lock<std::mutex> lock(mu);
    std::cout << "waiting thread one for condition" << std::endl;
    cond.wait(lock, []{ return shared_value ==1; });
    std::cout << "waiting ended for thread one for condition" << std::endl;

    std::cout << "Finishing thread one" << std::endl;

}


void thread_two() {
    std::cout << "starting thread two" << std::endl;
    std::unique_lock<std::mutex> lock(mu);
    std::cout << "waiting thread two for condition" << std::endl;
    cond.wait(lock, []{ return shared_value ==2; });
    std::cout << "waiting ended for thread two for condition" << std::endl;

    std::cout << "Finishing thread two" << std::endl;
}

void two_threads_with_condition() {

    std::thread t1(thread_one);  // start example with 2 concurrent threads
    std::thread t2(thread_two);
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

