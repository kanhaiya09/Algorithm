// https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1


#include <bits/stdc++.h> 
using namespace std;

bool isCycle(int V, vector<int> adj[]) {
    // Code here
    vector<bool> visited(V,false);
    for(int i = 0 ; i < V ; i++){
        if(!visited[i]){
            if(helper(i,visited,adj)==true)
                return true;
        }
    }
    return false;
}
    
    
bool helper(int src, vector<bool>& visited,vector<int>adj[]){
    queue<int> q;
    vector<int> parent(visited.size(),-1);

    visited[src] = true;
    parent[src] = -1;
    q.push(src);

    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int v : adj[u]){
            if(!visited[v]){
                visited[v] = true;
                parent[v] = u;
                q.push(v);
            }else{
                if(v != parent[u])
                    return true;
            }
        
        }
    }
    return false;
}