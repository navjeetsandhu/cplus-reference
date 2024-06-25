#include <iostream>

class Feet
{
private:
    int feet_;

public:
    explicit Feet(int feet) : feet_(feet) { }
    int operator+(int x) {
        feet_ += x;
        return feet_;
    }
    int operator-(int x) {
        feet_ -= x;
        return feet_;
    }

    int operator++() {
        feet_ ++;
        return feet_;
    }

    int operator--() {
        feet_ --;
        return feet_;
    }

    int cubed() const { return feet_*feet_*feet_; }


    friend std::ostream& operator<<(std::ostream &os, const Feet &my_obj) {
        os << "Feet = " << my_obj.feet_;
        return os;
    }


};

void testOperatorClass() {

    Feet ff(11);
    std::cout << ff << std::endl;

    std::cout << ff.cubed() << std::endl;
    std::cout << ff << std::endl;

    ++ff;

    std::cout << ff << std::endl;

    --ff;

    std::cout << ff << std::endl;

    ff + 3;

    std::cout << ff << std::endl;
    ff - 3;
    std::cout << ff << std::endl;



}