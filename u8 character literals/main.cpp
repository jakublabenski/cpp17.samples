//
//  main.cpp
//  u8 character literals
//
//  Created by Jakub Łabeński on 21.10.2017.
//  Copyright © 2017 Jakub Łabeński. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    // Only characters that can be represented with single UTF-8 code unit
    // are well formed
    // char ill_formed = u8'ł';
    char c = u8'a';
    
    const char s[] = u8"abłc";

    std::cout << "char c = " << c << std::endl;
    std::cout << "string s = " << s << std::endl;

    return 0;
}
