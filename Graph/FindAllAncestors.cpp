// https://leetcode.com/problems/all-ancestors-of-a-node-in-a-directed-acyclic-graph/

#include <bits/stdc++.h>
using namespace std;

 vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
    vector<vector<int>> adj(n);
    for(auto edge : edges){
        int u = edge[0];
        int v = edge[1];
        adj[u].push_back(v);
    }
    vector<vector<int>> ans(n);
    
    for(int i = 0 ; i < n ; i++){
        vector<bool> visited(n,false);    
        dfs(i,i,visited,ans,adj);
    }
    
    return ans;
}

void dfs(int u,int root,vector<bool> &visited,vector<vector<int>>&ans,vector<vector<int>>& adj){
    visited[u] = true;
    for(int v : adj[u]){
        if(!visited[v]){
            ans[v].push_back(root);
            dfs(v,root,visited,ans,adj);
        }
    }    
}
