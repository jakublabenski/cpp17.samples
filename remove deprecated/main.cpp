//
//  main.cpp
//  remove deprecated
//
//  Created by Jakub Łabeński on 21.10.2017.
//  Copyright © 2017 Jakub Łabeński. All rights reserved.
//

#include <iostream>

// removing deprecated exception specifications
// Only three allowed excdption specification syntaxes:
void f_noexcept() noexcept;
void f() noexcept(true);
// using throw() is deprecated:
void f_throws() throw();

#if __cplusplus < 201703L
void f_int() throw(int, float); // ill-formed in C++17

void on_terminate()
{
    // unexpected_handler, get_unexpected, set_unexpected, unexpected are
    // removed from standard
    std::unexpected_handler t = std::get_unexpected();
    std::set_unexpected(t);
    
    std::unexpected();
}

#endif

int main(int argc, const char * argv[]) {
#if __cplusplus < 201703L
    bool b = false;
    
    // deprecated bool increment removed:
    ++b;
    
    // deprecated register keyword removed:
    register int r = 0;
    
    // trigraphs are no longer required feature:
    int a??(10??);
    
    return r;
#endif
}
