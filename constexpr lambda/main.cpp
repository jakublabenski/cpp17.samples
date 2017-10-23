//
//  main.cpp
//  constexpr lambda
//
//  Created by Jakub Łabeński on 23.10.2017.
//  Copyright © 2017 Jakub Łabeński. All rights reserved.
//

constexpr int f1(int a)
{
    auto l = [a] {
        return a + 2;
    };

    return l();
}

constexpr auto l1 = f1(0);

constexpr int f2(int a)
{
    constexpr auto l = [] (int a) constexpr {
        return a + 2;
    };

    return l(a);
}

constexpr auto l2 = f2(0);

auto implicit_contexpr = [](int n) { return 2 * n; };
constexpr int i = implicit_contexpr(10);
