#include<iostream>


class Feet
{
private:
    int feet_;

public:
    explicit Feet(int feet) : feet_(feet) { }
    virtual int value() const { return feet_; }
};



class ImplicitFeet : public Feet{
private:
    int derivedFeet_;

public:
        ImplicitFeet(int feet) : Feet(feet), derivedFeet_(feet+2)  {}
        int value() const override { return  derivedFeet_; }
};



class ExplicitFeet : public Feet {
private:
    int derivedFeet_;

public:
    // The explicit keyword in C++ is used to prevent unwanted implicit conversions from happening.
    explicit ExplicitFeet(int feet) : Feet(feet), derivedFeet_(feet+1) {}
    int value() const override { return  derivedFeet_; }

};



void printFeet(const Feet& feet, std::string&& msg) {
    std::cout << msg << "Class Feet: " << feet.value() << "\n";
}


void testFeetClass() {
    Feet feet(10); // Explicit conversion from int to Feet
    printFeet(feet, "Base feet"); // Output: Feet: 10
    
    ImplicitFeet f = 10; // Implicit conversion from int to Feet
    printFeet(f, "Implicit conversion"); // Output: Feet: 12

    ExplicitFeet ff(20); // Explicit conversion from int to Feet
    printFeet(ff, "Explicit conversion"); // Output: Feet: 21

    auto *fff = new ExplicitFeet (32);
    printFeet(*fff, "new Object"); // Output: Feet: 33
    delete fff;

    auto explicitFeet = ff;
    printFeet(explicitFeet, "shallow copy class"); // Output: Feet: 21
}
