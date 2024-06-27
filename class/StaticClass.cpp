#include <iostream>

class MyStaticClass {
public:
    // Public method to increment and display the counter
    static void incrementCounter() {
        counter++;
        std::cout << "Static Class Counter: " << counter << std::endl;
    }

private:
    // Static data member declaration
    static int counter;
};

//n this example, counter is a static data member of the class MyClass.
// This means that counter is shared by all objects of the class, and we
// are required to define it outside the class. The incrementCounter method
// increments counter and displays its value. "Counter: " is also a static data member,
// specifically, it's a static string constant. It doesn't change and we're not
// required to initialize it outside the class in this case.

//Since incrementCounter is a static member function, it can only access
// static data members or other static member functions of the class.

int MyStaticClass::counter = 0;

void staticVariableClass() {

    // Static data member definition
    MyStaticClass::incrementCounter();

    MyStaticClass::incrementCounter();
}
