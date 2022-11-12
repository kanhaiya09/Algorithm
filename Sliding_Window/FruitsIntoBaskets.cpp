// https://leetcode.com/problems/fruit-into-baskets/
#include <bits/stdc++.h>
using namespace std;

int totalFruit(vector<int>& arr) {
    int i = 0;
    int ans = INT_MIN;
    unordered_map<int,int> mp;
    int cnt = 0;
    for(int j = 0 ; j < arr.size() ; j++){
        mp[arr[j]]++;
        if(mp[arr[j]]==1)
            cnt++;
        
        if(cnt>2){
            mp[arr[i]]--;
            if(mp[arr[i]]==0)
                cnt--;
            i++;
        }
        
        ans = max(ans,j-i+1);
    }
    return ans;
}


int main(){




}
