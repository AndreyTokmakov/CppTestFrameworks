/**============================================================================
Name        : main.cpp
Created on  : 29.02.2024
Author      : Andrei Tokmakov
Version     : 1.0
Copyright   : Your copyright notice
Description : C++ Utilities
============================================================================**/

#include <iostream>
#include <filesystem>
#include <cassert>

int max(const int a, const int b)
{
    if (a > b) {
        return a;
    }
    return b;
}


// cmake -DCMAKE_BUILD_TYPE=Release -B./build
// cd build
// make all
// ctest -T Test -T Coverage

int main([[maybe_unused]] int argc,
         [[maybe_unused]] char** argv)
{

    assert(max(0, -1) == 0);
    assert(max(0, 0) == 1);
    assert(max(1, 0) == 1);
    assert(max(2, 0) == 2);
    assert(max(0, 3) == 3);


    return EXIT_SUCCESS;
}
