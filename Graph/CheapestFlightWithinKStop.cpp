// https://leetcode.com/problems/cheapest-flights-within-k-stops/

#include <bits/stdc++.h> 
using namespace std;

int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    vector<list<pair<int,int>>> adj(n);
    for(auto edge: flights){
        int u = edge[0];
        int v = edge[1];
        int w = edge[2];
        adj[u].push_back({v,w});
    }
    
    vector<int> dist(n,INT_MAX);
    dist[src] = 0;

    queue<pair<int,int>> q;
    q.push({src,0}); 
    int level = 0;
    while(!q.empty() and level<=k){
        int size = q.size();
        while(size--){
            auto [u,cost] = q.front();
            q.pop();
            for(auto edge : adj[u]){
                int v = edge.first;
                int w = edge.second;
                   
                if(dist[v] > cost + w){  // why not use cost[u] + w ??
                    dist[v] = cost + w;  // consider testcase [[0,1,1],[0,2,5],[1,2,1],[2,3,1]]
                    q.push({v,dist[v]});
                    cout<<u <<" -->  " <<v <<" : " <<dist[v]<<"\n";
                }
            }
        }
        level++;
    }

    return dist[dst]==INT_MAX ? -1 : dist[dst];
}