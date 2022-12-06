// https://leetcode.com/problems/path-with-maximum-probability/


#include <bits/stdc++.h> 
#include <unordered_map>
using namespace std;

double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
    vector<double> dist(n,0.0);
    // vector<bool> visited(n,false);
    vector< list<pair<int,double>> >adj(n);
    for(int i = 0 ; i < edges.size() ; i++){
        int u = edges[i][0];
        int v = edges[i][1];
        double w = succProb[i];
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    dist[start] = 1.0;
    priority_queue< pair<double,int> > pq;
    pq.push({dist[start],start});
    
    while(!pq.empty()){
        auto tp = pq.top();
        pq.pop();
        double cost = tp.first;
        int curr = tp.second;
        //   cout<<"curr : " << curr <<" cost : " <<cost<<"\n";
        //   visited[curr] = true;    
        if(curr==end)
            break;
        for(auto p : adj[curr]){
            int child = p.first;
            double w = p.second;
            
        //     if(!visited[child]){
            if(dist[child] < dist[curr]*w)
            {
                dist[child] = dist[curr]*w;
                pq.push({dist[child],child});
            }
        //     }
        }
        
        
    }
    
    return dist[end];
}
