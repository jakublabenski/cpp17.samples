//
//  main.cpp
//  filesystem
//
//  Created by Jakub Łabeński on 23.10.2017.
//  Copyright © 2017 Jakub Łabeński. All rights reserved.
//

#include <iostream>
#include <ios>
#include <experimental/filesystem>

namespace fs = std::experimental::filesystem;

int main(int argc, const char * argv[]) {
    fs::path p(argc > 1 ? argv[1] : fs::current_path());

    std::cout << p << std::endl;
    std::cout << p.parent_path() << std::endl;

    std::cout << "directory_iterator:\n";
    fs::directory_iterator d(p.parent_path());
    for(auto sd : d) {
        auto status = sd.status();
        std::cout << "    " << std::hex << (size_t)status.permissions() << " " 
            << (int)status.type() 
           << " " << sd << '\n';
    }

    std::cout << "recursive_directory_iterator:\n";
    for(auto sd : fs::recursive_directory_iterator(p.parent_path())) {
        auto status = sd.status();
        std::cout << "    " << std::hex << (size_t)status.permissions() << " " 
            << (int)status.type() 
           << " " << sd << '\n';
    }


    return 0;
}
