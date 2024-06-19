#include <iostream>
#include <memory>

class Test {
public:
    Test() { std::cout << "Constructor is called\n"; }
    ~Test() { std::cout << "Destructor is called\n"; }
};

int test_unique_ptr() {
    {
        std::unique_ptr<Test> p1(new Test());
        {
            std::unique_ptr<Test> p2 = std::move(p1);
            std::cout << "p2 is going out of scope...\n";
        }  // The destructor is not called here, as p1 is still pointing to the object

        std::cout << "p1 is going to reset...\n";
        p1.reset();
        std::cout << "p1 is going out of scope...\n";
    }  // Here the destructor is called, as there's no shared_ptr pointing to the object anymore

    return 0;
}