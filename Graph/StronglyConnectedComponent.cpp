// https://practice.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1

#include<bits/stdc++.h>
using namespace std;

class Solution
{    
	public:
	//Function to find number of strongly connected components in the graph.
    /*
        1. sort the vertices in finishing time( postorder dfs)
        2. reverse the graph
        3. Perform dfs in reverse graph with postOrder vertices order
    */
    
    int kosaraju(int V, vector<int> adj[])
    {
        // Sort based on finishing time
        vector<bool> visited(V,false);
        stack<int> postOrder;
        for(int i = 0 ; i < V ; i++){
            if(!visited[i]){
                dfs(i,adj,visited,postOrder);
            }
        }
    
        //reverse the edge
        vector<int> adj2[V];
        for(int i = 0 ; i < V ; i++){
            for(int v: adj[i]){
                adj2[v].push_back(i);
            }
        }
        
        //call dfs in adj2 in postOrder manner
        vector<bool> visited2(V,false);
        int ans = 0;
        stack<int> val;
        while(!postOrder.empty()){
            int tp = postOrder.top();
            postOrder.pop();
            if(!visited2[tp]){
                ans++;
                dfs(tp,adj2,visited2,val);
            }
        }
        
        return ans;
    }
    
    void dfs(int s, vector<int> adj[] ,vector<bool>&visited , stack<int> &path){
        visited[s] = true;
        for(int v : adj[s])
        {
            if(!visited[v]){
                dfs(v,adj,visited,path);
            }
        }
        path.push(s);
    }
};