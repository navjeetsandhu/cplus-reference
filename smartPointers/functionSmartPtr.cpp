#include <iostream>
#include <memory>

struct Test {
    int value;
    explicit Test(int v) : value(v) {}
};

void pass_by_value(std::shared_ptr<Test> p) {
    std::cout << p.use_count() << std::endl;
    p->value = 20;
    p = std::make_shared<Test>(40);
}

void pass_by_reference(std::shared_ptr<Test>& p) {
    p->value = 30;
    std::cout << p.use_count() << std::endl;
    p = std::make_shared<Test>(40);
    std::cout << p.use_count() << std::endl;
}

int test_smart_ptr_function() {
    std::shared_ptr<Test> p = std::make_shared<Test>(10);
    std::cout << p.use_count() << std::endl;
    std::cout << p->value << std::endl;  // Prints "10"

    pass_by_value(p);
    std::cout << p->value << std::endl;  // Prints "20"

    pass_by_reference(p);
    std::cout << p->value << std::endl;  // Prints "40"

    return 0;
}