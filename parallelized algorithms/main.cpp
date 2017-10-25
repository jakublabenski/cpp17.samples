//
//  main.cpp
//  parallelized algorithms
//
//  Created by Jakub Łabeński on 25.10.2017.
//  Copyright © 2017 Jakub Łabeński. All rights reserved.
//

#include <iostream>

#include <algorithm>
#include <experimental/execution>

#if __has_include(<parallel>)
#include <parallel>
namespace s = std;
#define experimental_v 0
#else
//#include <experimental/parallel>
namespace s = std::experimental;
#define experimental_v 1
#endif

int main(int argc, const char * argv[]) {
    int a[4096];
    int b[4096];
    int i = 0;
    
    std::sort(std::execution::seq, a, a + 4096);
    return 0;
}
