// https://leetcode.com/problems/maximum-units-on-a-truck/

#include <bits/stdc++.h>
using namespace std;

bool MyCmp(vector<int> & lhs, vector<int>& rhs){
    return lhs[1] > rhs[1];
}

int maximumUnits(vector<vector<int>>& items, int truckSize) {
    sort(begin(items),end(items),MyCmp);
    int ans = 0;
    int i = 0;
    while(truckSize>0 and i<items.size()){
        if(truckSize-items[i][0]>0){
            ans += items[i][0]*items[i][1];
            truckSize -= items[i][0];
        }else{
            ans += (truckSize)*items[i][1];
            //cout<<"Ans : " <<ans <<"\n";
            break;
        }
        // cout<<"Ans : " <<ans <<"\n";
        // cout<<"trucksize : " <<truckSize <<"\n";
        i++;
    }
    
    return ans;
}