// https://leetcode.com/problems/subarray-sums-divisible-by-k/

/*
input  : [-7,2,3,0,-9]
    k  :  3


        0   -7   2   3   0   -9
sum :   0   -7  -5  -2  -2  -11 
rem :   0    2   1   1   1   1
cnt :   1    1   1   2   3   4
Ans     0    0   0   1   3   6

*/
#include <bits/stdc++.h>
using namespace std;

int subarraysDivByK(vector<int>& nums, int k) {
    int sum = 0 ;
    map<int,int> mp;
    mp[sum] = 1;
    int ans = 0;
    for(int i = 0 ; i < nums.size() ; i++){
        sum += nums[i];
        int rem = sum%k;
        if(rem<0)
            rem += k;
        if(mp.find(rem) != mp.end()){
            ans += mp[rem];
        }
        mp[rem]++;
    }
    return ans;
}

