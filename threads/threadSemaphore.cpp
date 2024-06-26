#include <iostream>
#include <thread>
#include <condition_variable>
#include <random>


class Semaphore {
public:
    explicit Semaphore (int count_ = 0)
        : count(count_) {}

    inline void notify() {
        std::unique_lock<std::mutex> lock(mtx);
        ++count;
        cv.notify_one();
    }

    inline void wait() {
        std::unique_lock<std::mutex> lock(mtx);

        while(count == 0){
            cv.wait(lock);
        }
        --count;
    }

private:
    std::mutex mtx;
    std::condition_variable cv;
    int count;
};

// Semaphore initialization
Semaphore sem(2);

int get_random_number()
{
    std::random_device r;
    std::default_random_engine e1(r());
    // Choose a random int between 0 and 100
    std::uniform_int_distribution<int> uniform_dist(0, 100);
    return uniform_dist(e1);
}



void worker(const int id) {
    for (int i=0;i<4;i++)
    {
        // Acquire the semaphore
        sem.wait();
        int delay = get_random_number();
        std::this_thread::sleep_for(std::chrono::milliseconds(delay));
        std::cout << "Thread " << id << " starts work number " << i << " "<< std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(delay * 100));
        std::cout << "Thread " << id << " has finished its work number " << i << " "<< std::endl;
        // Release the semaphore
        sem.notify();
    }
}

void run_worker_thread_with_semaphore() {

    std::cout << "Create and run threads" << std::endl;

    // Create and run threads
    std::thread t1(worker, 1);
    std::thread t2(worker, 2);
    std::thread t3(worker, 3);
    std::thread t4(worker, 4);

    t1.join();
    t2.join();
    t3.join();
    t4.join();
    std::cout << "Ending all threads" << std::endl;

}