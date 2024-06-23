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



class EmployeeReference
{
private:
    std::string mEmployeeName;

public:
    explicit EmployeeReference(std::string&   employeeName) : mEmployeeName(employeeName) {

    }
    virtual ~EmployeeReference() = default;

    const std::string& getName() const {
        return mEmployeeName;
    }
};

class CoopStudentReference: public EmployeeReference
{
public:
    explicit CoopStudentReference(std::string& employeeName) : EmployeeReference(employeeName) {}
};


void  testStringMove()
{
    std::string str1 = "Hello, world!";
    std::string str2 = std::move(str1);
    std::cout <<"str1: " << str1 << " str2:  " << str2 << std::endl;

}

void testStringReferenceClass()
{
    std::string str1 = "John  Reference";
    CoopStudentReference coop(str1);
    std::cout << coop.getName() << std::endl;
}


void testStringClass()
{
    CoopStudent coop("John");
    std::cout << coop.getName() << std::endl;
    testStringMove();
    testStringReferenceClass();

}

