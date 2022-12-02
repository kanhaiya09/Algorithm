// https://leetcode.com/problems/all-ancestors-of-a-node-in-a-directed-acyclic-graph/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
    vector<vector<int>> adj(n);
    // Get the indegree
    vector<int> indeg(n,0);
    for(auto edge : edges){
        int u = edge[0];
        int v = edge[1];
        adj[u].push_back(v);
        indeg[v]++;
    }
    vector<vector<int>> ans(n);
    vector<set<int>> ancestors(n);
    queue<int>q;
    
    for(int i = 0 ;  i < n ; i++)
    {
        if(indeg[i]==0)
            q.push(i);
    }
    
    while(!q.empty()){
        int u = q.front();
        q.pop();
        
        //add to ancestores
        for(int v : adj[u]){
            ancestors[v].insert(u);
            
            // also add all the ancestors of u to v
            for(auto parent : ancestors[u])
                ancestors[v].insert(parent);
            
            indeg[v]--;
            if(indeg[v]==0)
                q.push(v);
        }
    }
    
    for(int i = 0 ; i < n ; i++){
        ans[i] = vector(begin(ancestors[i]),end(ancestors[i]));
    }
    
    
    return ans;
}