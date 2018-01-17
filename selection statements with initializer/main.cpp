//
//  main.cpp
//  selection statements with initializer
//
//  Created by Jakub Łabeński on 23.10.2017.
//  Copyright © 2017 Jakub Łabeński. All rights reserved.
//

#include <iostream>
#include <string.h>

int f(int argc, const char * argv[]) {
    if (auto len = argc > 0 ? strlen(argv[0]) : 0; len < 10) {
        std::cout << "len is less than 10 (" << len << ")\n";
    } else {
        std::cout << "len is more than 10 (" << len << ")\n";
    }
    
    switch (auto len = strlen(argv[0])) {
        case 0:
            std::cout << "string is empty\n";
        case 1:
            std::cout << "string is one character long\n";
        default:
            std::cout << "len is 'default' (" << len << ")\n";
    }
    return 0;
}

struct A { int i = 0; };
int cond() { return 1; }

int f2()
{
    // expression in initializer:
    if (cond(); cond()) {}

    // declaration witout initialization:
    if (A a; a.i) {}

    // type definition in initialization:
    if (struct { int i = 0;} a; a.i) {}

    return 0;
}

int main(int argc, const char * argv[]) {
    f(argc, argv);
}