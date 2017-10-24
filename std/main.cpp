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
    auto a1 = std::make_any<int>(argc);
    
    std::cout << "sizeof any: " << sizeof a << '\n';
    
    if (std::any_cast<int>(a) <= 1) {
        return 1;
    }

    a = argv[1];
    if (std::any_cast<const char*>(a) == nullptr) {
        return 2;
    }

    a = std::string(std::any_cast<const char*>(a));
    std::cout << a.type().name() << '\n';

    a.reset();
    if (a.has_value()) {
        return 3;
    }

    try {
        auto d = std::any_cast<double>(a);
    } catch (const std::bad_any_cast& ex) {
        std::cout << "bad_any_cast: " << ex.what() << '\n';
    }
    
    return 0;
}
