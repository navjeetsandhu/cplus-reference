#include<iostream>


class Feet
{
private:
    int feet_;

public:
    explicit Feet(int feet) : feet_(feet) { }
    int value() const { return feet_; }
};



class ImplicitFeet : public Feet{

public:
        ImplicitFeet(int feet) : Feet(feet) {}
};



class ExplicitFeet : public Feet {

public:
    // The explicit keyword in C++ is used to prevent unwanted implicit conversions from happening.
    explicit ExplicitFeet(int feet) : Feet(feet) {}

};


void printFeet(const Feet& feet, std::string&& msg) {
    std::cout << msg << "Class Feet: " << feet.value() << "\n";
}


void testFeetClass() {
    ImplicitFeet f = 10; // Implicit conversion from int to Feet
    printFeet(f, "Implicit conversion"); // Output: Feet: 10
    ExplicitFeet ff(11); // Explicit conversion from int to Feet
    printFeet(ff, "Explicit conversion"); // Output: Feet: 10
}