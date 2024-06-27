#include <iostream>



void simpleArrayTest() {

    int array[][3] = {1,2,3,4,5, 6,7, 8, 9};



    // Declare a pointer to an array of 3 integers
    int (*ptr)[3];

    // Point ptr to the first element of array
    ptr = array;

    std::cout << "(*ptr)[0] " << (*ptr)[0] << " arguments:" << "\n";
    std::cout << "(*ptr)[1] " << (*ptr)[1] << " arguments:" << "\n";
    std::cout << "(*ptr)[2] " << (*ptr)[2] << " arguments:" << "\n";

    ptr++;

    std::cout << "(*ptr)[0] " << (*ptr)[0] << " arguments:" << "\n";
    std::cout << "(*ptr)[1] " << (*ptr)[1] << " arguments:" << "\n";
    std::cout << "(*ptr)[2] " << (*ptr)[2] << " arguments:" << "\n";
    ptr++;

    std::cout << "(*ptr)[0] " << (*ptr)[0] << " arguments:" << "\n";
    std::cout << "(*ptr)[1] " << (*ptr)[1] << " arguments:" << "\n";
    std::cout << "(*ptr)[2] " << (*ptr)[2] << " arguments:" << "\n";







}