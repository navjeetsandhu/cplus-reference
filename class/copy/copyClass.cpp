#include <iostream>

class Widget {
    std::unique_ptr<int> dataPtr;
public:
    explicit Widget(int data) {
        this->dataPtr = std::make_unique<int>(data);
        std::cout << "Constructor called!: " << *this;
    }
    // Implement deep copy in copy constructor
    Widget(const Widget& w) {
        this->dataPtr = std::make_unique<int>(*w.dataPtr);
        std::cout << "Copy constructor called!: " << *this;
    }

    friend std::ostream& operator << (std::ostream& os, const Widget& w) {
        os << "( ptr: " << w.dataPtr << ", value: " << *w.dataPtr << " )" <<std::endl;
        return os;
    }

    ~Widget() {
        std::cout << "Destructor called!: " << *this;

    }


};

void testDeepCopy() {
    // Constructor called
    Widget w1(10);

    std::cout << w1;

    // Deep Copy
    Widget w2 = w1;


    std::cout << w2;

}