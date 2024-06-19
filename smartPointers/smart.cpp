#include <iostream>
#include <memory>
using namespace std;


class Rectangle {
    int length;
    int breadth;
public:
    Rectangle(int l, int b)
    {
        length = l;
        breadth = b;
    }
    int area()
    {
        return length * breadth;
    }
};


int test_smart_ptr()
{
    shared_ptr<Rectangle> P1(new Rectangle(10, 5));
    cout << P1->area() << endl; // A=
    {
        shared_ptr<Rectangle> P2;
        P2 = P1;
        cout << P2->area() << endl; // B=
        cout << P1.use_count() << endl; // C=
    }
    weak_ptr<Rectangle> P3;
    P3 = P1;
    cout << P1.use_count() << endl; // D=
    shared_ptr<Rectangle> P4 = P3.lock();
    cout << P4->area() << endl;

    cout << P1.use_count() << endl; // E=
    return 0;
}
