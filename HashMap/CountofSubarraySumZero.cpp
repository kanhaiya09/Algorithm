// https://practice.geeksforgeeks.org/problems/zero-sum-subarrays1825/1
#include<bits/stdc++.h>
using namespace std;


typedef long long int ll;

ll findSubarray(vector<ll> arr, int n ) {
    ll ans = 0;
    unordered_map<ll,int> mp;
    ll sum = 0;
    mp[sum] = 1;
    for(int i = 0 ; i < n ; i++){
        sum += arr[i];
        if(mp.find(sum) != mp.end()){
            ans += mp[sum];
        }
        mp[sum]++;
    }
    return ans;
}