//
//  main.cpp
//  aggregate initialization of classes with base classes
//
//  Created by Jakub Łabeński on 21.10.2017.
//  Copyright © 2017 Jakub Łabeński. All rights reserved.
//

struct B {
    int b1;
    int b2;
};

struct S: B {
    int s;
};

int t1()
{
    // Default base class initialization:
    S s1{{}, 7};
    if (s1.s != 7) { return 1; }
    
    // With base class initialization:
    S s2{{1, 2}, 7};
    if (s2.s != 7) { return 2; }
    
    // Simple b1 initialization
    S s3{7};
    if (s3.b1 != 7) { return 3; }
    
    return 100 + s1.s + s2.s + s3.s;
}

struct S2;
struct B2 {
    friend struct S2;
    int b;
private:
    B2() {};
};

struct S2: B2 {};

int t2() {
    // This code is now ill-formed, tries to call private defalut constructor
    // S2 s4{};
    
    // This still is correct:
    S2 s4;
    
    return s4.b;
}

int main(int argc, const char * argv[]) {
    return t1() + t2();
}
