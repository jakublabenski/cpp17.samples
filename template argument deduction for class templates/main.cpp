//
//  main.cpp
//  template argument deduction for class templates
//
//  Created by Jakub Łabeński on 24.10.2017.
//  Copyright © 2017 Jakub Łabeński. All rights reserved.
//

#include <iostream>

template <typename T>
struct S {
    S(T t1, T t2) {}
};

int main(int argc, const char * argv[]) {
    auto s = S{1, 2};
    return 0;
}
