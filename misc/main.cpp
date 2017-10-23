//
//  main.cpp
//  misc
//
//  Created by Jakub Łabeński on 21.10.2017.
//  Copyright © 2017 Jakub Łabeński. All rights reserved.
//

// __has_include can be used to check if header file exists
#if __has_include(<iostream>)
#include <iostream>
#endif

// static_assert

// static_assert in C++11 and C++14
static_assert(1, "Message");
// static_assert in C++17
static_assert(1);

// hexadecimal floating literals
float f1 = 0x1234P1F;
auto f2 = 0x1234.5P1L;

// using attribute namespaces without repetition
[[using gnu: unused, noreturn]] void u();

// declaring non-type template parameters with auto
template <auto v> struct S {};
S<1> a;
S<'a'> b;

// standard and non-standard attributes
[[some_unknown_attribute]] void m1();
[[pp::some_unknown_attribute]] void m2();

// inline variables:
inline int inlined;

// Compatibility with prior version of standard:
struct S2 {
    static constexpr int n = 5; // definition in C++17 (declaration in C++14)
};
const int S2::n; // redundant declaration (definition in C++14)

#if 0
// Matching of template template-arguments excludes compatible templates
template <template <int> class> TT_Int {};
template <template <auto> class> TT_Auto {};
template <int> class T_Int {};
template <auto> class T_Auto {};

TT_Int<T_Int> tt1;
TT_Int<T_Auto> tt2;
TT_Auto<T_Int> tt3;
TT_Auto<T_Auto> tt4;
#endif

// pack expansions in using-declarations
template <typename... T>
struct S3 : T... {
    using T::operator()...;
};

namespace Ns {
    using INT = int;
    using FLOAT = float;
}

// Elements of using can be comma separated:
using Ns::INT, Ns::FLOAT;

int main(int argc, const char * argv[]) {
    return 0;
}
