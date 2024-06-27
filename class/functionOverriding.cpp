#include <iostream>

class Base
{
public:
    virtual void add(int a, int b) const { std::cout << " Base " << a+b << std::endl;};
    virtual void subtract(int a, int b) const { std::cout << " Base " << a-b << std::endl; };
};


class Derived: public Base
{
public:
    void add(int a, int b) const { std::cout << " Derived " << a+b << std::endl; };
    void subtract(float a, float b) const { std::cout << " Derived " << a-b << std::endl; };
};


void testDerivedClass() {
    Base* ptr;
    Derived derived;

    ptr = &derived;
    ptr->add(2,1);            // derived 3
    ptr->subtract(2,1);      // base 1
    ptr->subtract(2.4,1.2);  // base 1
}