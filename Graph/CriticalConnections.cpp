// https://leetcode.com/problems/critical-connections-in-a-network/

#include <bits/stdc++.h> 
using namespace std;


class Solution {
public:
    int timer = 0;
    vector<int> in;
    vector<int> low;
    vector<bool> visited;
    vector<vector<int>> ans;
    vector<list<int>> adj;    

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {    
        in.resize(n,0);
        low.resize(n,0);
        visited.resize(n,false);
        adj = vector<list<int>> (n);
        
        for(auto edge : connections){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        for(int i = 0 ; i < n ; i++){
            if(!visited[i]){
                dfs(i,-1);   
            }
        }
        return ans;
    }
    
    void dfs(int node,int parent){
        visited[node] = true;
        in[node] = timer;
        low[node] = timer;
        timer++;
        
        for(int child  : adj[node]){
            if(child==parent) continue;
            
            if(!visited[child]){
                dfs(child,node);
                
                low[node] = min(low[node],low[child]);
                
                // found bridge
                if(low[child] > in[node]){
                    ans.push_back({node,child});
                }
            
            }else{
                
                // back edge found : we can reach this node with shorter path from child 
                // so update the low of this node with in time of child 
                low[node] = min(low[node],in[child]);
            }
            
        }        
        
    }
};

