//
//  main.cpp
//  structured bindings
//
//  Created by Jakub Łabeński on 22.10.2017.
//  Copyright © 2017 Jakub Łabeński. All rights reserved.
//

#include <iostream>
//#include <pair>
#include <tuple>
#include <array>

int array[5];

// reference to elements:
auto& [a1, a2, a3, a4, a5] = array;
// copy of elements:
auto [a6, a7, a8, a9, a10] = array;

// for tuple:
auto [i1, f1, c1] = std::make_tuple(1, 1.0, 'a');

auto t = std::make_tuple(1, 2, "str");
auto [i2, i3, str] = t;

// for pair:
auto [p1, p2] = std::make_pair('a', 1);

// for array:
std::array<bool, 3> ba;
const auto [b1, b2, b3] = ba;

// for struct:
struct S {
    int i;
    int bf:4;
    float f;
};

auto [i, bf, f2] = S{};

// number of elements must match:
// auto [b5, b6] = ba; // ill-formed
// auto or auto&, with possible cv qualifiers allowed only:
// bool [b7, b8, b9] = ba; // ill-formed

int main(int argc, const char * argv[]) {
    return 0;
}
