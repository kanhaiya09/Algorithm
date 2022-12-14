// https://practice.geeksforgeeks.org/problems/hamiltonian-path2522/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    
    bool dfs(int s){
        cnt++;
        visited[s] = true;
        
        if(cnt==vertex){
            return true;
        }
        
        for(int v: adj[s]){
            if(!visited[v]){
                bool ans = dfs(v);
                if(ans)
                    return true;
            }
        }
        
        cnt--;
        visited[s] = false;
        return false;
    }
    
    
    bool check(int N,int M,vector<vector<int>> Edges)
    {
        cnt = 0;
        visited.resize(N+1,false);
        adj.resize(N+1);
        //build graph
        vertex = N;
        for(auto edge : Edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        for(int i = 1 ; i <= N ; i++){
            bool ans = dfs(i);
            if(ans)
                return true;
        }
        
        return false;
    }
    
    int cnt;
    vector<bool> visited;
    vector<vector<int>> adj;
    int vertex;
};

