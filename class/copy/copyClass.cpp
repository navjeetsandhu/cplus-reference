#include <iostream>


class BaseMe {
private:
    int count_;

public:
    explicit BaseMe(int count): count_(count) {};

    virtual ~BaseMe() = default;

    int getCount() const {
        return count_;
    }
};


class DeriveMe: public BaseMe {

private:
    std::unique_ptr<int> p;

public:
    explicit DeriveMe(int count) : BaseMe(count), p(new int(count)) {
    }

    using BaseMe::getCount;


    friend std::ostream& operator<<(std::ostream &os, const DeriveMe &my_obj) {
        os << "Pointer = " << my_obj.p << "  value = " << *my_obj.p << std::endl;
        return os;
    }
};


// Usage:
void testCopyClass()
{
    DeriveMe instance1(6);
    std::cout << instance1;
}