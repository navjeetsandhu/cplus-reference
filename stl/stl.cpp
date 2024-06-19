#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <atomic>

std::atomic<int> count(0);
int non_atomic_count = 0;

void sort_vector() {
    std::vector<int> v(10000,0);
    for(auto &val : v) {
        val = count++;
        non_atomic_count++;

    }

    auto f = [](int a, int b){ return a > b; };
    std::sort(v.begin(), v.end(), f);
}

void run_sort_vectors_threads() {
    sort_vector();
    std::thread t1(sort_vector);
    std::thread t2(sort_vector);
    std::thread t3(sort_vector);
    t1.join();
    t2.join();
    t3.join();
    std::cout << "\nAtomic count " << ' ' << count << "\n";
    std::cout << "\nNon atomic count " << ' ' << non_atomic_count << "\n";
}