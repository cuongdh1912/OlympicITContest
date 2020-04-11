//
//  ThuanChung.cpp
//  TestCpp
//
//  Created by Cuong Do Hung on 4/7/20.
//  Copyright © 2020 Cuong Do Hung. All rights reserved.
//
// Bài 3 đề thi olympic tin học sinh viên 2015

#include "ThuanChung.hpp"
int thuanChung(int n, int m, int* a) {
    if (n == 0) {
        return -1;
    }
    int result = -1;
    int genesL = 4;

    int **count = new int*[n]; // count the total number of existing "A", "C", "T", "G" in array a

    int count0[4] = {0, 0, 0, 0};
    
    count0[a[0]] += 1;
    count[0] = count0;
    // loop to count total number of existing "A", "C", "T", "G" in a
    for (int i = 1; i < n; i++) {
        int *countI1 = count[i - 1];
        int *c0 = new int[4];
        for (int j = 0; j < 4; j++) {
            c0[j] = countI1[j];
        }
        c0[a[i]] += 1;
        count[i] = c0;
    }
    for (int i = 1; i <= m; i++) {
        int du = n % i; // số dư
        int duplicate = n / i; // number of sub arrays
        int j = 0;
        // check that all total numbers of "A", "C", "T", "G" at count[n - du - 1] % duplicate == 0
        while (j < genesL) {
            if (count[n - du - 1][j] % duplicate > 0) {
                break;
            }
            j++;
        }
        if (j == genesL) { // if exist
            int k = i;
            // check the equation of all sub arrays
            while (k < n) {
                if (a[k] != a[k % i]) {
                    break;
                }
                k++;
            }
            if (k == n) {
                result = i;
                break;
            }
        }
    }
    delete[] count;
    return result;
}
/*int main(int argc, const char * argv[]) {
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
 */
