//
//  TachTu.cpp
//  TestCpp
//
//  Created by Cuong Do Hung on 4/5/20.
//  Copyright © 2020 Cuong Do Hung. All rights reserved.
//
// Olympic tin học sinh viên 2003 (đề thi khối không chuyên)
#include "TachTu.hpp"
#include <iostream>
using namespace std;
string s1 = "papa";
string s2 = "mama";
string s = "mpapamaa";
/*
    call tachtu function recursively
    i1: current index of s1
    i2: current index = s2
    result is a list of index of s1 & s2
 */
int *tachTu(int i1, int i2, int i, int *result) {
    // if go to over s's length, return to get result
    if (i == s.length()) {
        return result - s.length();
    }
    int *r1 = NULL;
    // if s1 is suitable
    if (i1 < s1.length() && s1[i1] == s[i]) {
        *result = 1;
        r1 = tachTu(i1+1, i2, i+1, (result + 1));
        if (r1) {
            return r1;
        }
    }
    // if s2 is suitable
    int *r2 = NULL;
    if (i2 < s2.length() && s2[i2] == s[i]) {
        *result = 2;
        r2 = tachTu(i1, i2 + 1, i + 1, (result + 1));
        if (r2) {
            return r2;
        }
    }
    
    return NULL;
}
//int main(int argc, const char * argv[]) {
//    int result[] = {};
//    int *r = tachTu(0, 0, 0, result);
//    for (int i = 0; i < s.length(); i++) {
//        cout<<*(r + i);
//    }
//    return 0;
//}
