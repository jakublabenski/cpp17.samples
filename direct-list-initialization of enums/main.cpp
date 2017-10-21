//
//  main.cpp
//  direct-list-initialization of enums
//
//  Created by Jakub Łabeński on 21.10.2017.
//  Copyright © 2017 Jakub Łabeński. All rights reserved.
//

#include <iostream>

enum byte : unsigned char {};

byte b1{42};
// Error: not direct-list-initialization
//byte b2 = { 42 };

enum class signed_byte : signed char {};

signed_byte sb1{-42};
// Error: norrowing conversion:
//signed_byte sb2{1000};

enum other_byte : char {
    C1, C2
};
// Error:
other_byte eb{42};

int main(int argc, const char * argv[]) {
    return 0;
}
