// https://practice.geeksforgeeks.org/problems/count-the-paths4332/1

#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    void dfs(int s,int d){
        if(s==d){
            cnt++;
            return;
        }
        // why not visited vector ?? because it is directed and acyclic graph
        for(auto v : adj[s]){
            dfs(v,d);
        }
    }


	int possible_paths(vector<vector<int>>edges, int n, int s, int d){
	    // Code here
	    adj.resize(n);
	    cnt = 0;
	    for(auto edge : edges){
	        int u = edge[0];
	        int v = edge[1];
	        adj[u].push_back(v);
	    }
	    
	    dfs(s,d);
	    return cnt;
	}
	int cnt;
	vector<vector<int>> adj;
};
