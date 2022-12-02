// https://practice.geeksforgeeks.org/problems/shortest-path-in-undirected-graph-having-unit-distance/1

#include <bits/stdc++.h> 
using namespace std;

vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
   vector<list<int>> adj(N);
    for(auto edge: edges){
        int u = edge[0];
        int v = edge[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    vector<int> dist(N, -1);
    vector<bool> visited(N, false);
    vector<int> parent(N,-1);
    dist[src]=0;
    visited[src] = true;
    parent[src] = -1;
    queue<int> q;
    q.push(src);
    
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int v : adj[u]){
            if(!visited[v])
            {
                dist[v] = dist[u]+1;
                parent[v] = u;
                visited[v] = true;
                q.push(v);
            }
            
        }
    }
    
    return dist;
	
    
}