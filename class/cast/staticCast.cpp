#include<iostream>


//Remember that static_cast does not perform any kind of runtime check and it is up
//to you to ensure that the casting operation is safe.


class BaseStaticCast
{
private:
    int feet_;

public:
    explicit BaseStaticCast(int feet) : feet_(feet) {
        std::cout << "BaseStaticCast constructor " << feet_ << std::endl;
    }
    int feet() const { return feet_; }
    virtual ~BaseStaticCast() = default;
    void printFeet() const {
        std::cout << "Base feet " << feet() << std::endl;
    }
};


class DerivedStaticCast : public BaseStaticCast {
    int height_;
public:
    // The explicit keyword in C++ is used to prevent unwanted implicit conversions from happening.
    explicit DerivedStaticCast(int feet, int height) : BaseStaticCast(feet) {
        height_ = height;
        std::cout << "DerivedStaticCast constructor " << height_ << std::endl;
    }
    int height() const { return height_; }
    void printHeight() const {
        std::cout << "Derived height " << height() << " Base feet " << feet() << std::endl;
    }
};




void printStaticCastDataReference(BaseStaticCast& feet) {
    try {
        auto& derive = static_cast<DerivedStaticCast&>(feet);

        derive.printHeight();
    }
    catch (const std::runtime_error& e) {
        std::cout << "Runtime error: " << e.what() << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "Standard exception: " << e.what() << std::endl;
    }
    catch (...) {
        std::cout << "Unknown exception caught" << std::endl;
    }
}


void printStaticCastDataPointer(BaseStaticCast* basePtr) {
    try {
        auto* derivedPtr = static_cast<DerivedStaticCast*>(basePtr);
        derivedPtr->printHeight();
    }
    catch (const std::runtime_error& e) {
        std::cout << "Runtime error: " << e.what() << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "Standard exception: " << e.what() << std::endl;
    }
    catch (...) {
        std::cout << "Unknown exception caught" << std::endl;
    }
}



void printStaticCastData(BaseStaticCast& feet) {
    printStaticCastDataReference(feet);
    printStaticCastDataPointer(&feet);
}

void printNumber(int* ptrNum)
{
    *ptrNum += 5; // modify the value
    std::cout << "Number: " << *ptrNum << std::endl;
}

void testStaticCast() {

    std::cout << "Printing normal scenario" << std::endl;
    DerivedStaticCast derived(3,4);
    printStaticCastData(derived);

    std::cout << "\n\nPrinting exception scenario" << std::endl;
    BaseStaticCast base(11);
    printStaticCastData(base);


    int i = 5;
    void* v_ptr = &i;
    int* i_ptr = static_cast<int*>(v_ptr);  // Converts a void pointer to int pointer
    std::cout << "Converts a void pointer to int pointer: " << *i_ptr << std::endl;


    // You should use reinterpret_cast only when you know exactly what
    // you are doing and you understand the implications. Misuse of
    // reinterpret_cast can lead to critical errors that are hard to diagnose.

    int *ptr = new int(10);
    auto addr = reinterpret_cast<uint64_t>(ptr);
    std::cout << "reinterpret_cast: " << addr << std::endl;
    delete ptr;

    const int num = 10;
    // const_cast most commonly used when you need to call a function that takes a
    // non-const argument, but you only have a const object.
    printNumber(const_cast<int*>(&num));
}