// https://leetcode.com/problems/minimum-operations-to-make-the-array-increasing/


#include <bits/stdc++.h>
using namespace std;

int minOperations(vector<int>& nums) {
    int ans = 0;
    int increase = nums[0];
    for(int i = 1 ; i < nums.size() ; i++){
        if(nums[i]>increase){
            increase = nums[i];
            continue;
        }
        else{
            int cnt =  increase+1-nums[i];
            ans += cnt;
            increase = increase+1;
        }    
    }
    return ans;
   
}