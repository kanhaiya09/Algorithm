// https://practice.geeksforgeeks.org/problems/shortest-path-in-undirected-graph-having-unit-distance/1

#include <bits/stdc++.h> 
using namespace std;

vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
    // code here   
    vector<list<int>> adj(N);
    for(auto edge: edges){
        int u = edge[0];
        int v = edge[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    vector<int> dist(N, INT_MAX);
    dist[src]=0;
    queue<int> q;
    q.push(src);
    
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int v : adj[u]){
            
            if(dist[v]>dist[u]+1){
                dist[v] = dist[u]+1;
                q.push(v);
            }
            
        }
    }
    
    for(int i = 0; i < N ;i++){
        dist[i] = dist[i]==INT_MAX? -1 : dist[i];
    }
    return dist;
}