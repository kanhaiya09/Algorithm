// https://www.codingninjas.com/codestudio/problems/bfs-in-graph_973002https://www.codingninjas.com/codestudio/problems/bfs-in-graph_973002

#include <bits/stdc++.h> 
using namespace std;


void  BFSHelper(int src,unordered_map<int,set<int>>& adj,vector<bool>& visited,vector<int>&res){
    
    queue<int> q;
    q.push(src);
    visited[src]  =true;
    
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        res.push_back(u);
        for(int v : adj[u]){
            if(!visited[v]){
                q.push(v);
                visited[v] = true;
            }
        }
    }    
}


vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    vector<int> res;
    vector<bool> visited(vertex,false);
    unordered_map<int,set<int>> adj;
    for(auto edge : edges){
        int u = edge.first;
        int v = edge.second;
        adj[u].insert(v);
        adj[v].insert(u);
    }
   
    
    for(int i = 0 ; i < vertex ; i++){
        if(!visited[i])
        {
            BFSHelper(i,adj,visited,res);
        }
    }
    
    return res;
}

