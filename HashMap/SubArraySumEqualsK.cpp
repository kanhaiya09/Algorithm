// https://leetcode.com/problems/subarray-sum-equals-k/


#include <bits/stdc++.h>
using namespace std;

int subarraySum(vector<int>& nums, int k) {
    unordered_map<int,int> mp;
    int sum = 0;
    mp[sum] = 1;
    int ans = 0;
    for(int i = 0 ; i < nums.size() ; i++){
        sum += nums[i];
        if(mp.find(sum-k) != mp.end()){
            ans += mp[sum-k];
        }
        mp[sum]++;
        
    }
    return ans;
}
