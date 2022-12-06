// https://leetcode.com/problems/network-delay-time/

#include <bits/stdc++.h> 
#include <unordered_map>
using namespace std;

int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    vector<int> dist(n+1,INT_MAX);
    vector< list<pair<int,int>>> adj(n+1);
    priority_queue< pair<int,int>, vector<pair<int,int>> , greater<pair<int,int>> > min_pq;
    for(auto edge : times){
        int u = edge[0];
        int v = edge[1];
        int w = edge[2];
        adj[u].push_back({v,w});
    }
    
    dist[k] = 0;
    min_pq.push({0,k});
    
    while(!min_pq.empty()){
        auto tp = min_pq.top();
        min_pq.pop();
        int u = tp.second;
        for(auto pr : adj[u]){
            int v = pr.first;
            int w = pr.second;
            
            //relax
            if(dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
                min_pq.push({dist[v],v});
            }
        }
    }
    
    int ans = INT_MIN;
    for(int  i = 1 ; i <= n ; i++){
        if(dist[i]==INT_MAX)
            return -1;
        else{
            ans = max(ans,dist[i]);
        }
    }
    return ans;
}