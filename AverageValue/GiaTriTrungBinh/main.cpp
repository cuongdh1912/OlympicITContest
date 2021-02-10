//
//  main.cpp
//  GiaTriTrungBinh
//
//  Created by Cuong Do on 2/11/21.
//

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;

struct Index {
    vector<pair<int, int> > ij;
};

map<int, vector<pair<int, int> > > indexList;


int main(int argc, const char * argv[]) {
    int n = 1000;
    vector<int> result;
//    int a[] = {2, 3, 5, 9, 18, 2};
    int a[1000] ;//= {4, 4, 2, 2, 3};
    FOR(i, n) {
        a[i] = random();
    }
    FOR(i, n - 1) {
        for (int j = i + 1; j < n; ++j) {
            if (indexList.count(a[i] + a[j]) > 0 ) {
                indexList[a[i] + a[j]].push_back(make_pair(i, j));
            } else {
                indexList[a[i] + a[j]] = {make_pair(i, j)};
            }
        }
    }
    
    for (auto &i : indexList) {
        sort(i.second.begin(), i.second.end());
    }
    
    FOR(i, n) {
        int a3 = 3 * a[i];
        FOR(j, n) {
            int ij = a3 - a[j];
            if (indexList.count(ij) > 0) {
                if (indexList[ij].size() > 2) {
                    result.push_back(a[i]);
                    break;
                }
                int found = false;
                for (auto il : indexList[ij]) {
                    if (il.first == j || il.second == j) {
                        found = true;
                        break;
                    }
                }
                if (found) {
                    continue;
                } else {
                    result.push_back(a[i]);
                    break;
                }
            }
        }
    }
    int k = result.size();
    return 0;
}
