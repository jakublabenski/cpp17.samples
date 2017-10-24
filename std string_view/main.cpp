//
//  main.cpp
//  std string_view
//
//  Created by Jakub Łabeński on 24.10.2017.
//  Copyright © 2017 Jakub Łabeński. All rights reserved.
//

#include <iostream>

#if __has_include(<string_view>)
#include <string_view>
namespace s = std;
#define experimental_v 0
#else
#include <experimental/string_view>
namespace s = std::experimental;
#define experimental_v 1
#endif


int main(int argc, const char * argv[]) {
    auto sv = s::string_view(argv[0]);
    
    std::cout << "sizeof string_view: " << sizeof(sv) << '\n';
    std::cout << "max_size: " << sv.max_size() << '\n';
    std::cout << "length: " << sv.length() << ", size: " << sv.size() << '\n';

    std::cout << sv << '\n';

    auto sv2 = sv.substr(3, sv.size() - 6);
    sv.remove_prefix(3);
    sv.remove_suffix(3);
    
    // [] returns const value, cannot assign:
    //sv[10] = 'a';
    
    std::cout << "sv == sv2: " << (sv == sv2) << '\n';
    std::cout << "sv : " << sv << '\n';
    std::cout << "sv2: " << sv2 << '\n';
    
    return 0;
}
