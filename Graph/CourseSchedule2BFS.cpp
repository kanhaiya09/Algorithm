// https://leetcode.com/problems/course-schedule-ii/
#include <bits/stdc++.h> 
using namespace std;

vector<int> findOrder(int n, vector<vector<int>>& edges) {
    //create adjacency list and calculate indegree of nodes
    vector<int> indeg(n,0);
    vector<list<int>> adj(n);
    for(auto edge : edges){
        int u = edge[1];
        int v = edge[0];
        adj[u].push_back(v);
        indeg[v]++;
    }
    
    //insert independent nodes first
    queue<int> q;
    for(int i = 0 ; i< n ; i++){
        if(indeg[i]==0)
            q.push(i);
    }
        

    // compute topological order
    vector<int> ans;
    int cnt = 0;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        cnt++;
        ans.push_back(u);
        
        for(int v : adj[u]){
            indeg[v]--;
            if(indeg[v]==0)
                q.push(v);
        }
        
    }

    //if cnt!=n this means cycle is present
    if(cnt != n)
        return {};
    return ans;
}

