//
//  main.cpp
//  refining expression evaluation order for idiomatic cpp
//
//  Created by Jakub Łabeński on 22.10.2017.
//  Copyright © 2017 Jakub Łabeński. All rights reserved.
//

#include <iostream>

int i_r;
int& r()
{
    std::cout << "then r() ";
    return i_r;
}

int i_l;
int& l()
{
    std::cout << "then l() ";
    return i_l;
}

struct S {
    S& g(int, const char* s = "") {
        std::cout << "then g" << s << "() ";
        return *this;
    }
    
    S& operator[](int) {
        std::cout << "then []() ";
        return *this;
    }
};

S& operator<< (S& s, int i) {
    std::cout << "then <<()";
    return s;
}

using SM = S& (S::*)(int);

SM sm()
{
    std::cout << "then sm() ";
    return &S::operator[];
}

S s_s;
S& s() {
    std::cout << "then s() ";
    return s_s;
}

S* ps()
{
    std::cout << "then ps() ";
    return &s_s;
}

int main(int argc, const char * argv[]) {
    // any assignment operator: the right operand is sequenced before the left
    // operand.
    // then r() then l()
    l() += r();
    std::cout << std::endl;
    
    // then ps() then l() then g()
    ps()->g(l());
    std::cout << std::endl;
    
    // then s() then g1() then l() then g2() then r() then g3()
    s().g(1, "1").g(l(), "2").g(r(), "3");
    std::cout << std::endl;
    
    // then s() then r() then <<()
    s() << r();
    std::cout << std::endl;

    // then s() then r() then []()
    s()[r()];
    std::cout << std::endl;

    // then ps() then sm() then r then []()
    (ps()->*sm())(r());
    std::cout << std::endl;

    return 0;
}
