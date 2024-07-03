cmake_minimum_required(VERSION 3.28)
project(examples)

set(CMAKE_CXX_STANDARD 14)

add_executable(examples
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
        threads/threadSemaphore.cpp
        lock/InterruptHandler.cpp
        array/simpleArray.cpp
        class/operatorOverload/operatorOverloadStruct.cpp
        class/operatorOverload/operatorOverloadClass.cpp
        class/cast/dynamicCast.cpp
        class/cast/staticCast.cpp
        class/staticVariable.cpp
        class/override/overrideOverload.cpp
        smartPointers/functionSmartPtr.cpp
        class/implicitClass.cpp
        class/singletonClass.cpp
        class/copy/copyClass.cpp)
