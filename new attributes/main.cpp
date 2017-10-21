//
//  main.cpp
//  new attributes
//
//  Created by Jakub Łabeński on 21.10.2017.
//  Copyright © 2017 Jakub Łabeński. All rights reserved.
//

#include <iostream>

// [[fallthrough]] attribute:
int fallthrough(int argc)
{
    switch (argc)
    {
        case 0:
            std::cout << "case 0\n";
            [[fallthrough]]; // semicolon is required
        case 1:
        case 2:
            // ill-formed:
            // [[fallthrough]];
            std::cout << "case 0-2\n";
            break;
        default:
            std::cout << "default\n";
            return 2;
            // ill-formed:
            // [[fallthrough]];
    }
    return 0;

}

// [[nodiscard]] attribute:
struct [[nodiscard]] S {};
enum class [[nodiscard]] E { E };

// Returns [[nodiscard]] type:
S ret_S() { return S{}; }
// Returns [[nodiscard]] type:
E ret_E() { return E::E; }

// Declared as [[nodiscard]] function:
[[nodiscard]] int ret_i() { return 0; }

void nodiscard()
{
    // Ignoring return value:
    ret_S();
    // Ignoring return value:
    ret_E();
    // Ignoring return value:
    ret_i();
    
    [[maybe_unused]] S s = ret_S();
    [[maybe_unused]] E e = ret_E();
    [[maybe_unused]] int i = ret_i();
}

// [[maybe_unused]] attribue:
struct [[maybe_unused]] S2 {
    // applied to field not to a type
    [[maybe_unused]] int i;
    
    [[maybe_unused]] int f();
    [[maybe_unused]] static int g();
};
enum class [[maybe_unused]] E2 {
    E,
    U [[maybe_unused]],
};
typedef S2 S3 [[maybe_unused]];
using S4 [[maybe_unused]] = S2;

[[maybe_unused]] void f([[maybe_unused]] int a)
{
    [[maybe_unused]] x:
    ;
};

// Entity may be declared without attribute and later declared with attribute,
// Entity is marked the first declaration with this attribute
void w();
[[maybe_unused]] void w();

int main(int argc, const char * argv[]) {
    fallthrough(argc);
    nodiscard();
}
