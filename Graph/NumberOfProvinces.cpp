// https://practice.geeksforgeeks.org/problems/number-of-provinces/1

#include <bits/stdc++.h> 
#include <unordered_map>
using namespace std;


class Solution {
  public:
    int numProvinces(vector<vector<int>> matrix, int V) {
        // code here
        int cnt = 0;
        visited.resize(V,false);
        vector<vector<int>> adj(V);
        
        // convert adjacency matrix to adjacency list 
        for(int i = 0 ; i < V ; i++){
            for(int j = 0 ;  j <V ; j++){
                if(matrix[i][j]==1){
                    adj[i].push_back(j);
                }
            }
        }
        for(int i = 0 ; i < V ; i++){
            if(!visited[i]){
                cnt++;
                dfs(i,adj);
            }    
        }
        return cnt;
    }
        
    void dfs(int s,vector<vector<int>> &adj){
        visited[s] = true;    
        for(int v : adj[s]){
            if(!visited[v]){
                dfs(v,adj);
            }
        }
    }
    vector<bool> visited;
};