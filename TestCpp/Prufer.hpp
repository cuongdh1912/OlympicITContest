//
//  Prufer.hpp
//  TestCpp
//
//  Created by Cuong Do Hung on 4/5/20.
//  Copyright © 2020 Cuong Do Hung. All rights reserved.
//

#ifndef Prufer_hpp
#define Prufer_hpp
#include <iostream>
#include <set>
#include <map>
#include <stdio.h>
#include <vector>

using namespace std;
struct Node {
    int value;
    set<Node> childs;
    Node(int value) {
        this->value = value;
        this->childs = {};
    }
    Node(){
        
    }
    //Other stuff
    bool operator<(const Node& loc2) const
    {
        return value < loc2.value;
    }
    bool operator!=(const Node& loc2) const {
        return value != loc2.value;
    }
};
class Prufer {
public:
    static Node prufer(vector<int> prufer, int n);
};
#endif /* Prufer_hpp */
