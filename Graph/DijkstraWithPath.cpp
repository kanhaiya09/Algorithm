// https://practice.geeksforgeeks.org/problems/shortest-path-in-weighted-undirected-graph/1?


#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        vector<int> dist(n+1,INT_MAX);
        vector<int> parent(n+1);
        for(int i = 1 ; i<=n  ;i++){
            parent[i] = i;
        }
        
        unordered_map<int,vector<pair<int,int>>> adj;
        
        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        
        dist[1] = 0;
        parent[1] = -1;
        
        priority_queue< pair<int,int>, 
                        vector<pair<int,int>>,
                        greater<pair<int,int>> > q;
                        
        q.push({0,1});
        
        while(!q.empty()){
            int d = q.top().first;
            int node = q.top().second;
            q.pop();
            
            for(auto edge : adj[node]){
                int v = edge.first;
                int weight = edge.second;
                
                if(d + weight < dist[v]){
                    dist[v] = d + weight;
                    parent[v] = node;
                    q.push({dist[v],v});
                }
            }
        }
        
        if(dist[n]==INT_MAX)
            return {-1};
        else{
            vector<int> path;
            int p = n;
            while(p !=-1){
                path.push_back(p);
                p = parent[p];
            }            
            reverse(begin(path),end(path));
            return path;
        }
    }
};
