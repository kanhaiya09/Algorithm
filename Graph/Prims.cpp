// https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1

#include <bits/stdc++.h> 
using namespace std;

//Function to find sum of weights of edges of the Minimum Spanning Tree.
int spanningTree(int V, vector<vector<int>> adj[])
{
    vector<bool> visited(V,false);
    vector<int> mst(V,INT_MAX);
    vector<int> parent(V,-1);

    //start with 0
    int src = 0;
    mst[src] = 0;
    parent[src] = -1;
    
    priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>> > minpq;
    minpq.push({0,src});
    
    while(!minpq.empty()){
        auto front = minpq.top();
        minpq.pop();
        
        // make this visited  !!!! very imp only diff with dijkstra
        int u = front.second;
        visited[u] = true;
        
        for(auto edge : adj[u]){
            int v = edge[0];
            int w = edge[1];
            
            if(!visited[v]){
                if(mst[v] > w){
                    mst[v] = w;
                    parent[v] = u;
                    minpq.push({w,v});
                }
            }
        }    
    }
    
    int ans = 0;
    for(int w : mst){
        ans += w;
    }
    
    return ans;
}