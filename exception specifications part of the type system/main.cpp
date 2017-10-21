//
//  main.cpp
//  exception specifications part of the type system
//
//  Created by Jakub Łabeński on 21.10.2017.
//  Copyright © 2017 Jakub Łabeński. All rights reserved.
//

#include <iostream>

// Standard refers to function pointers in three different ways:
// 'pointer to noexcept function',
// 'pointer to function' when function can throw exception,
// 'function pointer' when refering to both.

// pointer to noexcept function
using no_except = void (*)() noexcept;
// pointer to funciton
using except = void (*)();
// pointer to funciton
using no_except_false = void (*)() noexcept(false);

void f(no_except a)
{
    std::cout << "no_except: " << typeid(a).name() << std::endl;
}

void f(except a)
{
    std::cout << "except: " << typeid(a).name() << std::endl;
}

// Overloading:
void r();
// Functions cannot be overloaded soly on exception expecification
// void r() noexcept;

void m() {}
void m_noexcept() noexcept {}
void m_noexcept_false() noexcept(false) {}

int main(int argc, const char * argv[])
{
    f(m);
    f(m_noexcept_false);
    f(m_noexcept);
    
    // Implicit conversion:
    // pointer to noexept function can be implicitly converted to pointer
    // to function
    except e = m_noexcept;
    // is doesn't work in other direction:
    // no_except = m;

    e();
    return 0;
}
