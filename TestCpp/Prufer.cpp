//
//  Prufer.cpp
//  TestCpp
//
//  Created by Cuong Do Hung on 4/5/20.
//  Copyright © 2020 Cuong Do Hung. All rights reserved.
//
// Generate tree from Prüfer sequence

#include "Prufer.hpp"
/*
 purpose: generate tree
 parameters: prufer is a list of number which defines Prüfer sequence
 n: length of prufer vector
*/
Node Prufer::prufer(vector<int> prufer, int n) {
    int root = prufer[prufer.size() - 1];
    vector<Node> leafs;
    set<int> nodesSet;
    map<int, Node> nodesOfLeafs;
    // generate a set of numbers in prufer list
    for (int i : prufer) {
        nodesSet.insert(i);
    }
    // generate set of the rest numbers
    for (int i = 1; i <= n; i++) {
        if (nodesSet.find(i) == nodesSet.end()) { // if not in nodes
            Node node = Node(i);
            leafs.push_back(node);
        }
    }
    // generate tree
    while (prufer.size() > 0) {
        int p = prufer[0];
        prufer.erase(prufer.begin());
        Node node;
        if (nodesOfLeafs.find(p) != nodesOfLeafs.end()) {
            node = nodesOfLeafs[p];
        }else {
            node = Node(p);
            nodesOfLeafs[p] = node;
        }
        if (leafs.size() > 0) {
            node.childs.insert(leafs[0]);
            leafs.erase(leafs.begin());
        }
        nodesOfLeafs[p] = node;
        if (find(prufer.begin(), prufer.end(), p) == prufer.end()) { // not contains
            int index = 0;
            for (int i = 0; i < leafs.size(); i++ ) {
                if (leafs[i] < node) {
                    index++;
                }else {
                    break;
                }
            }
            leafs.insert(leafs.begin() + index, node);
        }
    }
    Node result;
    if (nodesOfLeafs.find(root) != nodesOfLeafs.end()) {
        result = nodesOfLeafs[root];
    }else {
        result = Node(root);
    }
    while (leafs.size() > 0) {
        if (leafs[0] != result) {
            Node child = leafs[0];
            result.childs.insert(child);
        }
        leafs.erase(leafs.begin());
    }
    cout<<result.value;
    return result;
}
//int main(int argc, const char * argv[]) {
//    //vector<int> p = {6, 9, 9, 3, 6, 6, 3};
//    vector<int> p = {5, 1, 1, 5};
//    solution(p, 6);
//    return 0;
//}
