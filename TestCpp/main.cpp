//
//  main.cpp
//  TestCpp
//
//  Created by Cuong Do Hung on 3/29/20.
//  Copyright © 2020 Cuong Do Hung. All rights reserved.
//

#include <iostream>
#include "Olympic2019B3Ngheu.hpp"
#include "ThuanChung.hpp"

int main(int argc, const char * argv[]) {
    // pure
    
    int m = 1000010;
    int l = 500000;
    int rL = l*2+1;
    int *r = new int[rL];
    for (int i = 0; i < l * 2; i += 2) {
        r[i] = 0;
        r[i+1] = 1;
    }
    r[rL - 1] = 3;
    int *a = new int[rL * 2 + 5];
    for (int i = 0; i < rL; i++) {
        a[i] = r[i];
        a[i+rL] = r[i];
    }
    for (int i = 0; i < 5; i++) {
        a[rL * 2 + i] = r[i];
    }
//        int m = 10;
//        String s = "ACATAGACATAGACATAGACA";
    int pure = thuanChung(rL * 2 + 5, m, a);
    std::cout<<pure;
}
