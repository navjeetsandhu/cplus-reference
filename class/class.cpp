#include<iostream>

class Feet {
public:
    // Implicit conversion from int to Feet
    //explicit Feet(int feet) : feet_(feet) { }
    explicit Feet(int feet) : feet_(feet) { }

    int value() const { return feet_; }

private:
    int feet_;
};

void printFeet(const Feet& feet) {
    std::cout << "Feet: " << feet.value() << "\n";
}


void implicitConversion() {
    Feet f = 10; // Implicit conversion from int to Feet
    printFeet(f); // Output: Feet: 10
}