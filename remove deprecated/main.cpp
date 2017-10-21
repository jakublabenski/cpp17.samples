//
//  main.cpp
//  remove deprecated
//
//  Created by Jakub Łabeński on 21.10.2017.
//  Copyright © 2017 Jakub Łabeński. All rights reserved.
//

int main(int argc, const char * argv[]) {
    bool b = false;
    
    // deprecated bool increment removed:
    ++b;
    
    // deprecated register keyword removed:
    register int r = 0;
    
    // trigraphs are no longer required feature:
    int a??(10??);
    
    return r;
}
