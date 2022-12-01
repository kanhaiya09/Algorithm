//  https://leetcode.com/problems/possible-bipartition/


#include <bits/stdc++.h> 
using namespace std;


bool helper(int src,vector<int> &color,unordered_map<int,list<int>>&adj){
    queue<int> q;
    q.push(src);
    color[src] = 1;
    
    while(!q.empty()){
        int u = q.front();
        q.pop();
        
        for(int v : adj[u]){
            if(color[v]==-1){
                q.push(v);
                color[v] = 1- color[u];
                
            }else{
                if(color[v]==color[u])
                    return false;
            }    
        }
    }
    return true;
}


bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
    //create adj list
    unordered_map<int,list<int>> adj;
    
    for(auto edge : dislikes){
        int u = edge[0];
        int v = edge[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    vector<int> color(n+1,-1);
    
    for(int i = 1;i <= n ; i++){
        if(color[i]==-1){
            if(helper(i,color,adj)==false)   
                return false;
        }
    }
    
    return true;
}