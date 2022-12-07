// https://leetcode.com/problems/all-paths-from-source-to-target/

#include <bits/stdc++.h> 
#include <unordered_map>
using namespace std;

vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
    vector<int> path;
    vector<vector<int>> ans;
    int n = graph.size();
    vector<bool> visited(n,false);
    
    dfs(0,n-1,visited,path,ans,graph);
    return ans;
}


void dfs(int src,int dest,vector<bool>& visited,vector<int>&path,vector<vector<int>> &ans,vector<vector<int>>& adj){
    visited[src] = true;
    path.push_back(src);
    
    if(src==dest){
        ans.push_back(path);
    }else{
        for(auto v : adj[src]){
            if(!visited[v]){
                dfs(v,dest,visited,path,ans,adj);
            }    
            
        }
    }
    visited[src] = false;
    path.pop_back();
}