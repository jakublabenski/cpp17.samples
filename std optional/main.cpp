//
//  main.cpp
//  std optional
//
//  Created by Jakub Łabeński on 24.10.2017.
//  Copyright © 2017 Jakub Łabeński. All rights reserved.
//

#include <iostream>

#if __has_include(<optional>)
#include <optional>
namespace s = std;
#define experimental_v 0
#else
#include <experimental/optional>
namespace s = std::experimental;
#define experimental_v 1
#endif

s::optional<std::string> get(int argc, const char* argv[])
{
    if (argc < 2) {
        return s::optional<std::string>{};
    }
    return s::make_optional(std::string{argv[1]});
}

int main(int argc, const char * argv[]) {
    auto opt = get(argc, argv);
    
    std::cout << "sizeof std::optional<std::string> " << sizeof(opt) << '\n';

    if (opt) {
        std::cout << "has value: " << *opt << '\n';
    } else {
        std::cout << "has no value: " << *opt << '\n';
    }
    opt = decltype(opt){};
    
    std::cout << "value when empty: " << opt.value_or(std::string{"empty!"})
        << '\n';
    
#if !experimental_v
    try {
        std::cout << "value when empty: " << opt.value() << '\n';
    } catch (const s::bad_optional_access& ex) {
        std::cout << "bad_optional_access: " << ex.what() << '\n';
    }
#endif
        
    return 0;
}
