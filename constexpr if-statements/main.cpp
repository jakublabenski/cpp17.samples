//
//  main.cpp
//  constexpr if-statements
//
//  Created by Jakub Łabeński on 22.10.2017.
//  Copyright © 2017 Jakub Łabeński. All rights reserved.
//

#include <iostream>

template <typename T>
void ft(T t)
{
    not_declared(t);
};

void f1(int a)
{
    if constexpr (sizeof(long) > sizeof(int)) {
    } else if constexpr (false) {
    label:
        ;
        // not instantiated:
        ft(1);
        // has to be true:
        static_assert(true);
        // has to be declared:
        // undeclared();
        goto label;
    } else {
        // ill-formed, labels declared in if constexpr statement can only be
        // referenced in that same sub-statement
        // goto label;
        return;
    }
}

auto f2()
{
    // return statements in a non-taken branch are ignored for return type
    // deduction
    if constexpr (false) {
        // discarded statements:
        return 1.0;
    } else {
        return 1;
    }
}

auto f3()
{
    // constexpr if can be combined with initializer, which doesn't have to be
    // constexpr
    if constexpr (int z = f2(); false) {
        // discarded statements:
        return 1.0;
    } else {
        return 1;
    }
}


int main(int argc, const char * argv[]) {
    return 0;
}
