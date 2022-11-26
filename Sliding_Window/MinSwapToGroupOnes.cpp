// https://leetcode.com/problems/minimum-swaps-to-group-all-1s-together-ii/

#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

int minSwaps(vector<int>& nums) {
    int k = 0;
    int n = nums.size();
    for(int i = 0 ; i < n ; i++){
        if(nums[i])
            k++;
    }
    
    int i = 0 ;
    int sum = 0;
    int ans = INT_MAX;
    for(int j = 0 ; j < 2*n ; j++){
        sum += nums[j%n];
        
        if(j-i+1==k){
            int z = j-i+1-sum;
            ans = min(ans,z);
            sum -= nums[i%n];
            i++;
        }
        
    }
    return ans==INT_MAX ? 0 : ans;
}

