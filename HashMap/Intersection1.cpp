// https://leetcode.com/problems/intersection-of-two-arrays/

#include <bits/stdc++.h>
using namespace std;

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int,int> freq;
    for(int n : nums1){
        freq[n]++;
    }
    
    vector<int> res;
    for(int n : nums2){
        if(freq.find(n) != freq.end()){
            res.push_back(n);
            freq.erase(n);
        }
    }
    
    return res;
}