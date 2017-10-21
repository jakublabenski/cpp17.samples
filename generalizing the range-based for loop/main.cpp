//
//  main.cpp
//  generalizing the range-based for loop
//
//  Created by Jakub Łabeński on 21.10.2017.
//  Copyright © 2017 Jakub Łabeński. All rights reserved.
//

#include <iostream>

struct Range {
    int first, last;
};

struct Iter {
    // Usedin loop condition:
    bool operator!=(int a)
    {
        std::cout << i << " != " << a << std::endl;
        return i < a;
    }
    
    // Used to increment __begin
    Iter operator++() {
        ++i;
        return *this;
    }
    
    // This is type of loop variable:
    int& operator*() {
        return i;
    }

    int i;
};

// __begin is type Iter
Iter begin(const Range& s) {
    return Iter{s.first};
}

// __end is int type
int end(const Range& s) {
    return s.last;
};

int main(int argc, const char * argv[]) {
    for (int& a : Range{5, 10}) {
        std::cout << a << std::endl;
    }

    return 0;
}
