//
//  main.cpp
//  dynamic memory allocation for over-aligned data
//
//  Created by Jakub Łabeński on 22.10.2017.
//  Copyright © 2017 Jakub Łabeński. All rights reserved.
//

#include <iostream>

struct JustThrow
{
};

struct S {
    S() { throw JustThrow(); }
    int a;
};

// alignas can be specified on variables, data members and tag types
struct alignas(64) AS: S {};

void* operator new(std::size_t size, std::align_val_t align, int s)
{
    std::cout << "new called: " << size << " align " <<
        static_cast<int>(align) << std::endl;
    return new unsigned char[size];
}

void operator delete(void*, std::align_val_t align, int s)
{
    std::cout << "delete called: " << " align " <<
        static_cast<int>(align) <<
    std::endl;
}

void* operator new(std::size_t size, int s)
{
    std::cout << "new called: " << size << " no align " << std::endl;
    return new unsigned char[size];
}

void operator delete(void*, int s)
{
    std::cout << "delete called: " << " no align " << std::endl;
}

int main(int argc, const char * argv[]) {
    // Placement delete will be called from placement new if construction
    // fails (throws exception). S throws in default constructor.
    try {
        new (1) S;
    } catch (JustThrow) {}

    try {
        new (2) AS;
    } catch (JustThrow) {}
    
    return 0;
}
