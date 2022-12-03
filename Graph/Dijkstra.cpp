// https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1

#include <bits/stdc++.h> 
using namespace std;

//Function to find the shortest distance of all the vertices
//from the source vertex S.
vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
{
    // Code here
    vector<int> dist(V,INT_MAX);
    dist[S] = 0;
    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>> > pq;
    pq.push({0,S});
    while(!pq.empty()){
        auto p = pq.top();
        pq.pop();
        int u = p.second;
        for(auto edge : adj[u]){
            int v = edge[0];
            int w = edge[1];
            if(dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
                pq.push({dist[v],v});
            }
        }
    }    
    return dist;
}