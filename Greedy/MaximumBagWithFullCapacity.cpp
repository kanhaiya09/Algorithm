// https://leetcode.com/problems/maximum-bags-with-full-capacity-of-rocks/

#include <bits/stdc++.h>
using namespace std;

bool MyCmp(pair<int,int>&lhs,pair<int,int>&rhs){
    return (lhs.second-lhs.first) > (rhs.second-rhs.first);
}

int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
    int n = rocks.size();
    vector<pair<int,int>> items(n);
    for(int i = 0 ; i < n ; i++){
        items[i] = {capacity[i],rocks[i]};
    }
    sort(begin(items),end(items),MyCmp);
    int ans = 0;
    for(int i = 0 ; i < n ; i++){
        if(items[i].first >= items[i].second and additionalRocks >=0 ) 
        {
            
            additionalRocks -= items[i].first - items[i].second;
            if(additionalRocks>=0)
                ans++;
        }
    }
    
    return ans;
}