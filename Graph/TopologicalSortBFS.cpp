// https://practice.geeksforgeeks.org/problems/topological-sort/1


#include <bits/stdc++.h> 
using namespace std;

//Function to return list containing vertices in Topological order. 
vector<int> topoSort(int V, vector<int> adj[]) 
{
    vector<int> ans;
    vector<int> indeg(V,0);
    
    // get the indegree of all nodes from adjacency list
    for(int i = 0 ; i < V ; i++){
        for(int v : adj[i]){
            indeg[v]++;
        }
    }
    //insert all the 0 indegree node to queue 
    queue<int> q;
    for(int i = 0 ; i < V ; i++){
        if(indeg[i]==0)
            q.push(i);
    }
    //cout<<q.size();
    
    while(!q.empty()){
        int u = q.front();
        ans.push_back(u);
        
        //remove front from queue
        q.pop();   
        
        //as the front node is removed, all of adjacent of this node will have it's indegree decreased by 1
        for(int v : adj[u]){
            indeg[v]--;
            
            //if indegree of adjacent become 0, add it in queue
            if(indeg[v]==0)
                q.push(v);
        }
    }
    return ans;
}
	