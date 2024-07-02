#include<iostream>


class Base
{
private:
    int feet_;

public:
    explicit Base(int feet) : feet_(feet) { }
    int feet() const { return feet_; }
    virtual ~Base() = default;
    void printFeet() const {
            std::cout << "Base feet " << feet() << std::endl;
    }
};


class Derived : public Base {
    int height_;
public:
    // The explicit keyword in C++ is used to prevent unwanted implicit conversions from happening.
    explicit Derived(int feet, int height =1) : Base(feet) {
        height_ = height;
    }
    int height() const { return height_; }
    void printHeight() const {
        std::cout << "Derived height " << height() << " Base feet " << feet() << std::endl;
    }
};




void printDataReference(Base& feet) {
    try {
        auto& derive = dynamic_cast<Derived&>(feet);
        // If we get here, dynamic_cast was successful
        derive.printHeight();
    }
    catch (const std::bad_cast& e) {
        // Dynamic cast failed
        std::cout << "std::bad_cast exception" << std::endl;
        feet.printFeet();
    }
}


void printDataPointer(Base* basePtr) {
    auto* derivedPtr = dynamic_cast<Derived*>(basePtr);
    if(derivedPtr != nullptr) {
        derivedPtr->printHeight();
    }
    else {
        std::cout << "Null dynamic cast" << std::endl;
        basePtr->printFeet();
    }
}



void printData(Base& feet) {
    printDataReference(feet);
    printDataPointer(&feet);
}



void testDynamicCastClass() {
    Derived derived(3,4);
    printData(derived);
    Base base(11);
    printData(base);
}