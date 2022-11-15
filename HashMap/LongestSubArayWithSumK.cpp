// https://practice.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1


#include <bits/stdc++.h>
using namespace std;

int lenOfLongSubarr(int A[],  int N, int K) 
{ 
    int prefixSum = 0;
    int ans = 0;
    unordered_map<int,int> mp;
    mp[prefixSum] = -1;    
    
    for(int i = 0 ; i < N ; i++){
        prefixSum += A[i];
    
        if(mp.find(prefixSum-K) != mp.end()){
            ans = max(ans,i-mp[prefixSum-K]);
        }
    
        if(mp.find(prefixSum)==mp.end())
            mp[prefixSum] = i;
        
    }
    return ans;
}



