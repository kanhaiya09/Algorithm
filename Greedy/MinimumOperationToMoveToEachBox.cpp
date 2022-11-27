// https://leetcode.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box/

#include <bits/stdc++.h>
using namespace std;

vector<int> minOperations(string boxes) {
    int n = boxes.size();
    vector<int> res(n,0);
    for(int i = 0; i<n;i++){
        for(int j = 0; j < n ; j++){
            if(boxes[j]=='1' and j !=i){
                res[i] += abs(j-i);
            }
        }
    }
    return res;
}

