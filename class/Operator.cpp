#include <iostream>


struct Vector {
    int x;
    int y;
};

Vector operator+(const Vector& a, const Vector& b) {
    return Vector{a.x + b.x, a.y + b.y};
}

std::ostream& operator<<(std::ostream& os, const Vector& vec) {
    os << "(" << vec.x << ", " << vec.y << ")";
    return os;
}


void testOperatorOverload() {
    Vector a{2,3};
    Vector b{3,4};

    std::cout << a+b << std::endl;
}