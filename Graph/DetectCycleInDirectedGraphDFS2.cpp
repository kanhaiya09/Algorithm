// https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1

#include <bits/stdc++.h> 
using namespace std;


// Function to detect cycle in a directed graph.
bool isCyclic(int V, vector<int> adj[]) {
    // code here
    vector<bool> visited(V,false);
    vector<bool> dfsVisited(V,false);
    
    
    for(int i = 0 ; i < V ; i++){
        if(!visited[i]){
            bool ans = dfs(i,visited,dfsVisited,adj);
            if(ans==true)
                return ans;
        }
    }
    
    return false;
}

bool dfs(int u, vector<bool>& visited,vector<bool>& dfsVisited, vector<int> adj[]){
    
    visited[u] = true;
    dfsVisited[u] = true;

    for(int v : adj[u]){
        if(!visited[v]){
            bool ans = dfs(v,visited,dfsVisited,adj);
            if(ans==true)
                return true;
        }else{
            if(dfsVisited[v])
                return true;
        }
    }
    
    dfsVisited[u] = false;
    return false;
}