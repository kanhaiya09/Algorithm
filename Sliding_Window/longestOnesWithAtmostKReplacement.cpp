#include <bits/stdc++.h>
using namespace std;

/*
Given a binary array nums and an integer k, 
return the maximum number of consecutive 1's in the array 
if you can flip at most k 0's.


Input:
nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
Output: 6
Explanation:  [1,1,1,0,0,1,1,1,1,1,1]


Input: 
nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
Output: 10
Explanation: [0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]

*/


int longestOnes(vector<int>& nums, int k) {
    int i = 0 ; 
    int j = 0;
    int ans = INT_MIN;
    int cnt= 0 ;
    for(int j = 0 ;  j < nums.size() ; j++){
        if(nums[j]==0)
            cnt++;
        
        while(cnt>k){
            if(nums[i]==0)
                cnt--;
            i++;
        }
        ans = max(ans,j-i+1);
    }
    return ans;
}

