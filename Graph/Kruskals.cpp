// https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1

#include <bits/stdc++.h> 
using namespace std;

class Solution{
    static bool cmp(vector<int>& lhs , vector<int>&rhs){
	    return lhs[2]<rhs[2];  // sort in ascending order of weight
	}
	
	
	int find(int u){
	    if(parent[u]==u)
	        return u;
	   else return parent[u] = find(parent[u]);
	}
    
    void union_(int u,int v){
        int uid = find(u);
        int vid = find(v);
        
        if(uid==vid)
            return;
        
        if(rank[uid]<=rank[vid]){
            parent[uid] = vid;
            rank[vid]++;
        }else{
            parent[vid] = uid;
            rank[uid]++;
        }
        
    }
    
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        
        //create edge vector for undirected graph from adjacency list
        vector< vector<int> > edges;
        vector<bool> visited(V,false);
        for(int u = 0 ; u < V ; u++){
            for(auto edge: adj[u]){
                int v = edge[0];
                int w = edge[1];
                if(!visited[v]){
                    edges.push_back({u,v,w});
                }
            }
            visited[u] = true;
        }
        sort(begin(edges),end(edges),cmp);
        /*for(int i = 0 ; i < edges.size() ; i++){
            cout<<edges[i][0] <<" --> ";
            cout << "{" <<edges[i][1] << "," <<edges[i][2]<<"} ";  
            cout<<"\n";
        }*/
        
        //Union find algo
        parent.resize(V);
        for(int i = 0 ; i < V ; i++){
            parent[i] = i;
        }
        rank.resize(V,1);
        
        
        //iterate through the sorted edge and if they are in different component unify them
        int mst = 0;
        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            
            int pu = find(u);
            int pv = find(v);
            
            if(pv==pu)
                continue;
            else
            {
                union_(u,v);
                mst += w;
            }
        }
        
        return mst;
    }
    
    vector<int> parent;
    vector<int> rank;
};