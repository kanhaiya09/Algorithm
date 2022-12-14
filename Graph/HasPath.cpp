// https://leetcode.com/problems/find-if-path-exists-in-graph/

#include<iostream>
#include <vector>
#include <list>
using namespace std;

class Solution {
public:
    bool dfs(int s,int d){
        if(s==d)
            return true;
        
        visited[s] = true;
        for(int v : adj[s]){
            if(!visited[v]){
                bool ans = dfs(v,d);
                if(ans)
                    return true;
            }
        }
        return false;
    }
    
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        adj.resize(n);
        visited.resize(n,false);
        
        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        return dfs(source,destination);
    }
    vector<bool> visited;
    vector<list<int>>adj;
};