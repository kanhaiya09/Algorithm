// https://leetcode.com/problems/longest-consecutive-sequence/

#include <bits/stdc++.h>
using namespace std;


int longestConsecutive(vector<int>& nums) {
    unordered_map<int,bool> mp;
    //make all numbers as starting of sequence
    for(int n : nums){
        mp[n] = true;
    }
    //for each number check whether its previous is also present in map,
    //if yes, it cant be start of sequence so mark it as false;
    for(int n : nums){
        if(mp.find(n-1) != mp.end()){
            mp[n] = false;
        }
    }
    // Now for each starting sequence, it's map value will be true
    int ans = 0;
    for(int n : nums){
        if(mp[n]){
            int i = 1;
            //check how far the sequence is present in map 
            while(mp.find(n+i) != mp.end()){
                i++;
            }
            if(i>ans){
                ans = i;
            }
        }
    }
    return ans;
}

