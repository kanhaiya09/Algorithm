// https://leetcode.com/problems/minimum-subsequence-in-non-increasing-order/

#include <bits/stdc++.h>
using namespace std;

vector<int> minSubsequence(vector<int>& nums) {
    sort(begin(nums),end(nums),greater<int>());
    long sum = 0;
    sum = accumulate(begin(nums),end(nums),0);
    vector<int>ans;
    long curr = 0;
    for(int i = 0 ; i < nums.size() ; i++){
        ans.push_back(nums[i]);
        curr += nums[i];
        sum -= nums[i];
        if(curr>sum)
            break;
    }
    return ans;
}