//
//  main.cpp
//  lambda capture of this by value
//
//  Created by Jakub Łabeński on 21.10.2017.
//  Copyright © 2017 Jakub Łabeński. All rights reserved.
//

#include <iostream>

struct S {
    void f() {
        std::cout << "0: l = " << l << std::endl;
        
        // Modifies this->l
        [this] () mutable { this->l = 1; }();
        std::cout << "1: l = " << l << std::endl;
        
        // Modifies copy of this
        [*this] () mutable { this->l = 2; }();
        std::cout << "2: l = " << l << std::endl;
        
        // Modifies copy of this
        [=, *this] () mutable { this->l = 3; }();
        std::cout << "3: l = " << l << std::endl;
    }
    int l = 0;
};

int main(int argc, const char * argv[]) {
    S s;
    s.f();
    return 0;
}
