// https://practice.geeksforgeeks.org/problems/topological-sort/1


#include <bits/stdc++.h> 
using namespace std;


vector<int> topoSort(int V, vector<int> adj[]) 
{
    vector<bool> visited(V,false);
    stack<int> postOrderDFS;
    
    for(int i = 0 ; i < V ; i++){
        if(!visited[i]){
            dfs(i,visited,postOrderDFS,adj);   
        }
    }
    
    vector<int> ans;
    while(!postOrderDFS.empty()){
        ans.push_back(postOrderDFS.top());
        postOrderDFS.pop();
    }
    
    return ans;
}

void dfs(int u,vector<bool> &visited,stack<int> &postOrderDFS,vector<int>adj[]){
    visited[u] = true;
    for(int v : adj[u]){
        if(!visited[v]){
            dfs(v,visited,postOrderDFS,adj);    
        }    
    }
    postOrderDFS.push(u);
}
