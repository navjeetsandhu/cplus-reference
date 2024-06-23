#include <string>
#include <utility>
#include <iostream>

class Employee
{
private:
    std::string mEmployeeName;

public:
    explicit Employee(std::string   employeeName) : mEmployeeName(std::move(employeeName)) {

    }
    virtual ~Employee() = default;

    const std::string& getName() const {
        return mEmployeeName;
    }
};

class CoopStudent: public Employee
{
public:
    explicit CoopStudent(std::string employeeName) : Employee(std::move(employeeName)) {}
};


void testStringClass()
{
    CoopStudent coop("John");
    std::cout << coop.getName();
}