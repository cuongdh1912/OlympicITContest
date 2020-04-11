//
//  Olympic2019B3Ngheu.cpp
//  TestCpp
//
//  Created by Cuong Do Hung on 4/6/20.
//  Copyright © 2020 Cuong Do Hung. All rights reserved.
//
// Bài 3 đề thi olympic tin học sinh viên 2019
#include "Olympic2019B3Ngheu.hpp"
vector<int> thuHoachNgheu(int n, int m, int **ngheu, int t, int redline, int **thu) {
    vector<int> result;
    int currentRedline = redline;
    int xeTai = 0;
    // loop to get items
    for (int k = 0; k < t; k++) {        
        int row1, row2, col1, col2;
        if (thu[k][0] == 2) {
            currentRedline = thu[k][1];
            continue;
        }else if (thu[k][0] == 1) {
            xeTai = thu[k][1];
            col1 = thu[k][2];
            row1 = thu[k][3];
            col2 = thu[k][4];
            row2 = thu[k][5];
            // thu hoach
            bool leftToRight = true;
            int total = 0;
            for (int i = row1 - 1; i < row2; i++) {
                for (int j = leftToRight?(col1 - 1):(col2 - 1); (leftToRight && j < col2) || (!leftToRight && j >= col1 - 1); j += leftToRight? 1 : -1) {
                    if (ngheu[i][j] > currentRedline) {
                        int nextThu = ngheu[i][j] - currentRedline;
                        if (nextThu + total <= xeTai) {
                            total += nextThu;
                        }
                        if (total == xeTai) {
                            break;
                        }
                    }
                }
                if (total == xeTai) {
                    break;
                }
                leftToRight = !leftToRight;
            }
            result.insert(result.end(), total);
        }
    }
    return result;
}
/*
 int main(int argc, const char * argv[]) {
     int n = 3, m = 4;
     int **ngheu = new int*;
     int a[][4] = {{1, 2, 3, 1}, {2, 3, 1, 2}, {3, 1, 2, 3}};
     for (int i = 0; i < n ; i++ ) {
         *ngheu = a[i];
         ngheu += 1;
     }
     ngheu -= n;
     int t = 3, redline = 2;
     int **thu;
     thu = new int*;
     int b[] = {1, 10, 1, 1, 2, 3};
     *thu = b;
     int c[] = {2, 1};
     *(thu + 1) = c;
     int d[] = {1, 10, 1, 2, 4, 2};
     *(thu + 2) = d;

     vector<int> result = thuHoachNgheu(n, m, ngheu, t, redline, thu);
     for (int i:result) {
         std::cout<<i<<" ";
     }
     return 0;
     
 }
 */
