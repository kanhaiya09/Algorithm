// https://leetcode.com/problems/find-the-town-judge/

#include <bits/stdc++.h> 
#include <unordered_map>
using namespace std;

int findJudge(int n, vector<vector<int>>& trust) {
    vector<int> out(n+1,0);
    vector<int> in(n+1,0);
    for(auto edge : trust){
        int u = edge[0];
        int v = edge[1];
        out[u]++;
        in[v]++;
    }
    int ans = -1;
    for(int i = 1 ; i <= n ;i++){
        if(out[i]==0 and in[i]==n-1)
            ans = i;
    }
    return ans;
}