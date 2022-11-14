// https://practice.geeksforgeeks.org/problems/count-distinct-elements-in-every-window/1

#include<bits/stdc++.h>
using namespace std;

vector <int> countDistinct (int A[], int n, int k)
{
    vector<int> ans;
    unordered_map<int,int> mp;
    int i = 0;
    for(int j = 0;  j < n ; j++){
        mp[A[j]]++;
        
        if(j-i+1==k){
            ans.push_back(mp.size());
            mp[A[i]]--;
            if(mp[A[i]]==0)
                mp.erase(A[i]);
            i++;
        }
    }
    return ans;
}