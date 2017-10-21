//
//  main.cpp
//  attributes for namespaces and enumerators
//
//  Created by Jakub Łabeński on 21.10.2017.
//  Copyright © 2017 Jakub Łabeński. All rights reserved.
//

namespace [[deprecated]] Ns {
    enum E {
        V1,
        V2 [[deprecated]]
    };
}

namespace [[deprecated]] {
    
}

int main(int argc, const char * argv[]) {
    Ns::E e = Ns::V2;
    return e;
}
