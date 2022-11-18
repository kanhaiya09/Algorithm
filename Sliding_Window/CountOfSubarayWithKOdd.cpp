// https://leetcode.com/problems/count-number-of-nice-subarrays/


#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;


 int atMostKOdd(vector<int>& nums,int k){
    int ans = 0;
    int i = 0 ; 
    int cnt = 0;
    for(int j = 0 ; j < nums.size() ; j++){
        //calculate
        if(nums[j]%2==1){
            cnt++;
        }
        
        if(cnt<=k){
            ans += j-i+1;
        }
        
        while(cnt>k){
            if(nums[i]%2==1)
                cnt--;
            i++;
            if(cnt<=k)
                ans += j-i+1;
        }
        
    }
    return ans;
}

int numberOfSubarrays(vector<int>& nums, int k) {
    return atMostKOdd(nums,k)-atMostKOdd(nums,k-1);
}