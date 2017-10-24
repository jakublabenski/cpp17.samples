//
//  main.cpp
//  std variant
//
//  Created by Jakub Łabeński on 24.10.2017.
//  Copyright © 2017 Jakub Łabeński. All rights reserved.
//

#include <iostream>
#include <variant>

struct C
{
};

auto& operator<< (std::ostream& out, C c)
{
    out << "C";
    return out;
}

struct Visitor
{
    template <typename T>
    void operator()(T&& t) {
        std::cout << "visited: " << typeid(T).name() << std::endl;
    }


};

int main(int argc, const char * argv[]) {
    // no references, array or void.
    auto v = std::variant<C, std::string, C, int>(42);

    std::cout << "sizeof variant " << sizeof v << '\n';
    std::cout << "sizeof std::string " << sizeof(std::string)   << '\n';

    std::cout << "index = " << v.index() << '\n';
    std::cout << "get = " << std::get<int>(v) << '\n';

    try {
        // std::cout << "get = " << std::get<C>(v) << '\n';
        std::cout << "get = " << std::get<std::string>(v) << '\n';
    } catch (const std::bad_variant_access& ex) {
        std::cout << "bad_variant_access: " << ex.what() << '\n';
        if (std::get_if<1>(&v) == nullptr) {
            // std::get_if<C>(&v) == nullptr;
            std::cout << "not a string\n";
        }
        v = "hello world";
    }

    std::visit(Visitor{}, v);

    std::cout << std::get<std::string>(v) << '\n';

    return 0;
}
