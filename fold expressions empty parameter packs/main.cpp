//
//  main.cpp
//  fold expressions empty parameter packs
//
//  Created by Jakub Łabeński on 21.10.2017.
//  Copyright © 2017 Jakub Łabeński. All rights reserved.
//

#include <iostream>

template <typename... Args>
constexpr auto sum(Args... args)
{
    // operators: +, *, &, |
    return (args + ...);
}

template <typename... Args>
constexpr auto alt(Args... args)
{
    // operators: ||, &&, , (comma)
    return (args || ...);
}

int main(int argc, const char * argv[]) {
    // Compilation error:
    //sum();
    
    // Always returns false
    static_assert(!alt());
    
    return 0;
}
