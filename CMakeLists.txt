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
        smartPointers/sharedPointer.cpp
        smartPointers/uniquePointer.cpp
        threads/twoThread.cpp
        string/stringClass.cpp
        class/OperatorClass.cpp
        threads/threadSemaphore.cpp
        class/staticVariableCast.cpp
        lock/InterruptHandler.cpp
        array/simpleArray.cpp
        class/Operator.cpp
        class/functionOverrideAndOverload.cpp
        smartPointers/functionSmartPtr.cpp
        class/dynamicCast.cpp
        class/staticCast.cpp
        class/staticVariableCast.cpp
        class/singletonClass.cpp)
