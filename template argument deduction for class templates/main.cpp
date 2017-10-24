//
//  main.cpp
//  template argument deduction for class templates
//
//  Created by Jakub Łabeński on 24.10.2017.
//  Copyright © 2017 Jakub Łabeński. All rights reserved.
//

#include <iostream>
#include <string>

template <typename T>
struct S {
    S(T t1, T t2) {}
};

// explicit deduction guides:
template<typename T, T a = 0>
S(T, T) -> S<double>;


int main(int argc, const char * argv[]) {
    auto s1 = S{1, 2};
    S s2{'1', '2'};

    std::cout << typeid(s1).name() << '\n';
    std::cout << typeid(s2).name() << '\n';

    return 0;
}
