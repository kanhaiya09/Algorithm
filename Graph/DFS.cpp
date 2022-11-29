// https://www.codingninjas.com/codestudio/problems/dfs-traversal_630462

#include <bits/stdc++.h> 
using namespace std;


void dfs(int src,vector<bool>&visited,unordered_map<int,set<int>>&adj,vector<int> &ans){
    visited[src] = true;
    ans.push_back(src);
    
    for(int v : adj[src]){
        if(!visited[v]){
            dfs(v,visited,adj,ans);
        }
    }
}


vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    vector<vector<int>> res;
    unordered_map<int,set<int>> adj;
    
    for(auto edge  : edges){
        int u = edge[0];
        int v = edge[1];
        adj[u].insert(v);
        adj[v].insert(u);
    }
       
    vector<bool> visited(V,false);
    vector<int> ans;
    for(int i = 0 ; i <V ; i++){
        if(!visited[i]){
            dfs(i,visited,adj,ans);
            res.push_back(ans);
            ans.clear();
        }
    }
    
    return res;
}