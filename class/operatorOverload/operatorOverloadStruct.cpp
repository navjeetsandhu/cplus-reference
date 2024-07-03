#include <iostream>


struct Vector {
    int x;
    int y;
    Vector(int a, int b): x(a), y(b){};
};


Vector operator+(const Vector& a, const Vector& b) {
    return Vector{a.x + b.x, a.y + b.y};
}


Vector operator*(const Vector& a, const Vector& b) {
    return Vector{a.x * b.x, a.y * b.y};
}

std::ostream& operator<<(std::ostream& os, const Vector& vec) {
    os << "(" << vec.x << ", " << vec.y << ")";
    return os;
}


void testOperatorOverloadStruct() {
    Vector a{2,3};
    Vector b(3,4);
    Vector c(2,3);

    std::cout << a+b*c << std::endl;
}