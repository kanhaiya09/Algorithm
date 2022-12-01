// https://leetcode.com/problems/course-schedule/

#include <bits/stdc++.h> 
using namespace std;

enum colors{WHITE,GREY,BLACK};
class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& edges) {
        vector<int> color(n,WHITE);
        unordered_map<int,list<int>> adj;
        for(auto edge : edges){
            int u = edge[1];
            int v = edge[0];
            adj[u].push_back(v);
        }
        
        for(int i = 0 ; i < n ; i++){
            if(color[i]==WHITE){
                if(isCycle(i,color,adj))
                    return false;
            }
        }
        return true;
    }
    
    bool isCycle(int u, vector<int>&color,unordered_map<int,list<int>>&adj){
        color[u] = GREY;
        
        for(int v : adj[u]){
            if(color[v]==WHITE){
                if(isCycle(v,color,adj))
                    return true;
            }else{
                if(color[v]==GREY)
                    return true;
            }   
        }
        
        color[u] = BLACK;
        return false;
    }
};
