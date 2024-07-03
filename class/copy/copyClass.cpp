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

    Widget& operator = (const Widget& w) {
        std::cout << "Assignment operator called!: ";
        if(this == &w) {
            std::cout << " this == &w: " << *this;
            return *this;
        }
        std::cout << " this != &w start: " << *this;
        this->dataPtr = std::make_unique<int>(*w.dataPtr);
        std::cout << " this != &w after: " << *this;
        return *this;
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

    std::cout << "w1: " << w1; // w1: ( ptr: 0x6000019a0030, value: 10 )

    // Deep Copy
    Widget w2 = w1;


    std::cout << "w2: " << w2; // w2: ( ptr: 0x6000019a0040, value: 10 )

    std::cout << "Creating constant reference w3, No copy constructor called" << std::endl;
    const Widget& w3 = w1;
    std::cout << "w3: " << w3;  //w3: ( ptr: 0x6000019a0030, value: 10 )

    Widget w4(15);
    std::cout << "w4: " << w4;


    std::cout << std::endl << std::endl << "Assigment "  << std::endl;
    std::cout << "w4 before assignment: " << w4;
    w4 = w1;
    std::cout << "w4 after assignment: " << w4;

    std::cout << std::endl << "w1=w3" << std::endl;
    w1 = w3;


    std::cout << std::endl << std::endl<< "Ending" << std::endl;
}