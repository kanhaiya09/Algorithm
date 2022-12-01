// https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

#include <bits/stdc++.h> 
using namespace std;

bool isCycle(int V, vector<int> adj[]) {
    // Code here
    vector<bool> visited(V,false);
    for(int i = 0 ; i < V ; i++){
        if(!visited[i]){
            if(dfs(i,-1,visited,adj)==true)
                return true;
        }
    }
    return false;
}


bool dfs(int u,int parent,vector<bool>& visited,vector<int>adj[]){
    visited[u] = true;
    for(int v : adj[u]){
        if(!visited[v]){
            bool ans = dfs(v,u,visited,adj);
            if(ans==true)
                return true;
        }else{
            if(v!= parent)
                return true;
        }
    }
    return false;
    
}