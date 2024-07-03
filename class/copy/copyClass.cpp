#include <iostream>

class Widget {
    int* dataPtr;
public:
    explicit Widget(int data) {
        this->dataPtr = new int(data);
        std::cout << "Constructor called! Value: " << *this->dataPtr << std::endl;
    }
    // Implement deep copy in copy constructor
    Widget(const Widget& w) {
        this->dataPtr = new int(*w.dataPtr);
        std::cout << "Copy constructor called! Value: " << *this->dataPtr << std::endl;
    }

    ~Widget() {\
        std::cout << dataPtr << " Destructor called!" << std::endl;
        delete dataPtr;

    }

    void print() {
        std::cout << dataPtr << " Data value: " << *dataPtr << std::endl;
    }
};

void testDeepCopy() {
    // Constructor called
    Widget w1(10);

    // Deep Copy
    Widget w2 = w1;

    w1.print(); // prints 10
    w2.print(); // prints 10

}