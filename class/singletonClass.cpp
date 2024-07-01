#include <iostream>

//Making the constructor private to prevent other objects from using the new
// operator with our singleton class.
//Initialize a static instance of the class within the class itself.
//Create a public static method which provides a global point of access to the
// singleton object.

class Singleton
{
public:
    int  counter{};
    // This static method is the global access point for the singleton object.
    static Singleton& getInstance()
    {
        static Singleton instance; // Guaranteed to be destroyed, instantiated on first use.
        return instance;
    }

    // We delete the methods we don't want to be accessible.
    Singleton(Singleton const&) = delete;   // Copy constructor
    void operator=(Singleton const&) = delete; // Assignment operator


private:
    Singleton() {}  // Private so that it can  not be called
};

// Usage:
int testSingletonClass()
{
    auto & instance1 = Singleton::getInstance();
    instance1.counter = 8;

    auto & instance2 = Singleton::getInstance();

    std::cout << "instance1.counter = " << instance1.counter << std::endl;
    std::cout << "instance2.counter = " << instance2.counter << std::endl;
}