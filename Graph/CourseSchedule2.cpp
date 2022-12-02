// https://leetcode.com/problems/course-schedule-ii/
#include <bits/stdc++.h> 
using namespace std;


enum Colors{WHITE,GREY,BLACK};

class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& edges) {
        vector<int> color(n,WHITE);
        stack<int> course;
        unordered_map<int,list<int> > adj(n);
        for(auto edge : edges){
            int u = edge[1];
            int v = edge[0];
            adj[u].push_back(v);
        }
        
        for(int i = 0 ; i < n ; i++){
            if(color[i]==WHITE){
                bool isCycle = dfs(i,color,course,adj);
                if(isCycle)
                    return {};
            }
        }
        
        vector<int> ans;
        while(!course.empty()){
            ans.push_back(course.top());
            course.pop();
        }
        
        return ans;
    }
    
    
    bool dfs(int u , vector<int>& color, stack<int>&ans, unordered_map<int,list<int>> &adj){
        color[u] = GREY;
        for(int v : adj[u]){
            if(color[v]==WHITE){
                bool res = dfs(v,color,ans,adj);
                if(res==true)
                    return true;
            }else{
                if(color[v]==GREY)
                    return true;
            }
        }
        color[u] = BLACK;
        ans.push(u);
        return false;
    }
    
};
