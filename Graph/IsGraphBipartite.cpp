// https://leetcode.com/problems/is-graph-bipartite/


#include <bits/stdc++.h> 
using namespace std;


bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n,-1);
        
        for(int i = 0 ; i < n ; i++){
            if(color[i]==-1){
                if(helper(i,color,graph) == false)
                    return false;
            }
        }
        return true;
    }
    
bool helper(int src,vector<int>& color,vector<vector<int>>& graph){
    queue<int> q;
    q.push(src);
    color[src] = 1;    
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int v : graph[u]){
            if(color[v]==-1)
            {
                q.push(v);
                color[v] = 1 - color[u];
            }else{
                if(color[v]==color[u])
                    return false;
            }
        }
        
    }
    return true;
    
}