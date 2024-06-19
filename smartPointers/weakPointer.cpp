#include <iostream>
#include <memory>
using namespace std;


class Rectangle {
    int length;
    int breadth;

public:
    Rectangle(int l, int b)
    {
        cout << "Constructor called" << endl;
        length = l;
        breadth = b;
    }
    int area() const
    {
        return length * breadth;
    }

};

// You cannot use weak pointers to initialise new objects in memory,
// point to memory owned by unique pointers,
// or point to ordinary stack objects.
int test_weak_ptr()
{

    shared_ptr<Rectangle> P1(new Rectangle(10, 5));

    cout << "Area  " << P1->area() << endl; // A=
    {
        shared_ptr<Rectangle> P2;
        P2 = P1;
        cout << "use_count  " << P1.use_count() << endl;
    }
    weak_ptr<Rectangle> P3;
    P3 = P1;
    cout << "use_count  " << P1.use_count() << endl;

    shared_ptr<Rectangle> P4 = P3.lock();
    cout << "use_count  " << P1.use_count() << endl;

    weak_ptr<Rectangle> P5;
    P5 = P1;
    shared_ptr<Rectangle> P6 = P5.lock();
    cout << "use_count  " << P1.use_count() << endl;

    cout << "P6 use_count before P6 reset " << P6.use_count() << endl;
    P6.reset();
    cout << "P1 use_count after P6 reset " << P1.use_count() << endl;
    cout << "P6 use_count after P6 reset " << P6.use_count() << endl;

    P1.reset();
    cout << "P1 use_count  after P1 reset " << P1.use_count() << endl;
    cout << "P4 use_count  after P1 reset " << P4.use_count() << endl;
    P4.reset();
    cout << "P4 use_count  after P4 reset " << P4.use_count() << endl;

    return 0;
}
