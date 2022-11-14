// https://leetcode.com/problems/find-the-difference-of-two-arrays/

#include<bits/stdc++.h>
#include <unordered_set>
using namespace std;


vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
    unordered_set<int> s1(begin(nums1),end(nums1));
    unordered_set<int> s2(begin(nums2),end(nums2));
    
    vector<vector<int>> res;
    vector<int> v1;
    for(int n : s1){
        if(s2.find(n) == s2.end()){
            v1.push_back(n);
        }
    }
    res.push_back(v1);
    v1.clear();
    for(int n : s2){
        if(s1.find(n) == s1.end()){
            v1.push_back(n);
        }
    }
    res.push_back(v1);
    return res;
}