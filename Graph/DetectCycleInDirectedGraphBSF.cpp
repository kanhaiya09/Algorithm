// https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1


#include <bits/stdc++.h> 
using namespace std;

// Function to detect cycle in a directed graph.
bool isCyclic(int V, vector<int> adj[]) {
    vector<int> indeg(V,0);
    queue<int>q;
    for(int i = 0 ; i < V ; i++){
        for(int v : adj[i]){
            indeg[v]++;
        }
    }
    
    for(int i = 0 ; i < V ; i++){
        if(indeg[i]==0)
            q.push(i);
    }
    
    int cnt = 0;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        cnt++;
        
        for(int v : adj[u]){
            indeg[v]--;
            if(indeg[v]==0)
                q.push(v);
        }
        
    }
    //if cnt==V this means no cycle present
    //cout<<cnt<<"\n";
    return cnt!=V;
        
}