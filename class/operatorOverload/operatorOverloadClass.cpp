#include <iostream>

class Feet
{
public:
    int feet_;
    int height_;

    explicit Feet(int feet = 0, int height = 0) : feet_(feet), height_(height){ }
    Feet operator+(const Feet& feet) const {
        Feet f;

        f.feet_ = feet_ + feet.feet_;
        f.height_ = height_ + feet.height_;

        return f;
    }
    Feet operator-(const Feet& feet) const {
        Feet f;

        f.feet_ = feet_ - feet.feet_;
        f.height_ = height_ - feet.height_;

        return f;
    }

    Feet operator++() {
        feet_ ++;
        height_ ++;
        return *this;
    }

    Feet operator--() {
        feet_ ++;
        height_ ++;
        return *this;
    }


    friend std::ostream& operator<<(std::ostream &os, const Feet &my_obj) {
        os << "(feet = " << my_obj.feet_ << "  height = " << my_obj.height_ << ")" << std::endl;
        return os;
    }


};

void testOperatorOverloadClass() {

    Feet ff(11, 12);
    Feet fff(111, 121);
    std::cout << ff << std::endl;

    std::cout << ff << std::endl;

    ++ff;

    std::cout << ff << std::endl;

    --ff;

    std::cout << ff << std::endl;

    Feet f = fff + ff;

    std::cout << f << std::endl;

    f = fff - ff;
    std::cout << f << std::endl;
}