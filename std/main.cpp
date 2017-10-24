//
//  main.cpp
//  std
//
//  Created by Jakub Łabeński on 24.10.2017.
//  Copyright © 2017 Jakub Łabeński. All rights reserved.
//

#include <iostream>
#include <any>

int main(int argc, const char * argv[]) {
    auto a = std::any(argc);
    
    if (a > 1) {
        a = argv[1];
    }
    
    return 0;
}
