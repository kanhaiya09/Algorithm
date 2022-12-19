// https://leetcode.com/problems/find-eventual-safe-states/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool dfs(int s,vector<vector<int>>& adj){
        visited[s] = true;
        dfsVisit[s] = true;

        for(int v : adj[s]){
            if(!visited[v]){
                if(dfs(v,adj)==true)
                    return true;
            }else{
                if(dfsVisit[v])
                    return true;
            }
        }

        safe[s] = true;
        dfsVisit[s] = false;
        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        visited.resize(n,false);
        dfsVisit.resize(n,false);
        safe.resize(n,false);

        for(int i = 0 ; i < n ; i++){
            if(!visited[i]){
                dfs(i,graph);
            }
        }

        vector<int> ans;
        for(int i = 0 ; i < n ; i++){
            if(safe[i])
                ans.push_back(i);
        }

        return ans;
    }

    vector<bool> visited;
    vector<bool> dfsVisit;
    vector<bool> safe;
};