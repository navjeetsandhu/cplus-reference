#include <iostream>
#include "includes/myHeader.h"


int main(int argc, char* argv[]) {

    std::cout << "You have entered " << argc << " arguments:" << "\n";

    for (int i = 0; i < argc; ++i) {
        std::cout << argv[i] << "\n";
    }

    test_smart_ptr_function();
    return 0;
}
