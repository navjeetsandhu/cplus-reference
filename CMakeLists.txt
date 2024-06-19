cmake_minimum_required(VERSION 3.28)
project(examples)

set(CMAKE_CXX_STANDARD 14)

add_executable(examples
        class/class.cpp
        smartPointers/smart.cpp
        stl/stl.cpp
        threads/thread.cpp
        main.cpp
        includes/myHeader.h
        lock/binarySemaphore.cpp
        smartPointers/weakPointer.cpp
        smartPointers/sharedPointer.cpp)
