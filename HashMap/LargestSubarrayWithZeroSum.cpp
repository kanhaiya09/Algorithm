// https://practice.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1

#include<bits/stdc++.h>
using namespace std;


int maxLen(vector<int>&A, int n){   
    int sum = 0;
    int ans = 0;
    map<int,int> mp;
    mp[0] = -1;
    
    for(int i = 0 ; i < n ; i++){
        sum += A[i];
        if(mp.find(sum) ==mp.end()){
            mp[sum] = i; 
        }else{
            int local = i-mp[sum];
            if(local>ans){
                ans = local;
            }
        }
    }
    return ans;
}

