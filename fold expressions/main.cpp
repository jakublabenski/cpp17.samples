//
//  main.cpp
//  fold expressions
//
//  Created by Jakub Łabeński on 21.10.2017.
//  Copyright © 2017 Jakub Łabeński. All rights reserved.
//

#include <iostream>

struct S {
    int i = 0;
};

auto operator+ (S a, S b)
{
    std::cout << "Sum: " << a.i << " " << b.i << std::endl;
    return S{ a.i + b.i };
}

auto operator+ (S a, int b)
{
    std::cout << "Sum: " << a.i << " int " << b << std::endl;
    return S{ a.i + b };
}

auto operator+ (int a, S b)
{
    std::cout << "Sum: int " << a << " " << b.i << std::endl;
    return S{ a + b.i };
}

template<typename... Args>
constexpr auto unary_right_fold(Args... args)
{
    return (args + ...);
}

template<typename... Args>
constexpr auto unary_left_fold(Args... args)
{
    return (... + args);
}

template<typename... Args>
constexpr auto binary_right_fold(Args... args)
{
    return (args + ... + 30);
}

template<typename... Args>
constexpr auto binary_left_fold(Args... args)
{
    return (30 + ... + args);
}

template<typename Arg, typename... Args>
auto sum_cpp14(Arg arg, Args... args)
{
    return arg + sum_cpp14(args...);
}

template<typename Arg>
auto sum_cpp14(Arg arg)
{
    return arg;
}

int main(int argc, const char * argv[]) {
    std::cout << "unary left:" << std::endl;
    unary_right_fold(S{1}, S{2}, S{3}, S{4});
    
    std::cout << "unary right: " << std::endl;
    unary_left_fold(S{1}, S{2}, S{3}, S{4});

    std::cout << "binary left:" << std::endl;
    binary_right_fold(S{1}, S{2}, S{3}, S{4});

    std::cout << "binary right: " << std::endl;
    binary_left_fold(S{1}, S{2}, S{3}, S{4});

    std::cout << "cpp14: " << std::endl;
    sum_cpp14(S{1}, S{2}, S{3}, S{4});

    return 0;
}
