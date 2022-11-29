// https://www.codingninjas.com/codestudio/problems/bfs-in-graph_973002https://www.codingninjas.com/codestudio/problems/bfs-in-graph_973002

#include <bits/stdc++.h> 
#include <unordered_map>
using namespace std;

void  BFSHelper(int src,unordered_map<int,list<int>>& adj,vector<bool>& visited,vector<int>&res){
        
    queue<int> q;
    q.push(src);
    visited[src]  =true;
    
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        res.push_back(u);
        for(int v : adj[u]){
            if(!visited[v]){
                q.push(v);
                visited[v] = true;
            }
        }
    }    
}


vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    vector<int> res;
    vector<bool> visited(vertex,false);
    unordered_map<int,list<int>> adj;
    for(auto edge : edges){
        int u = edge.first;
        int v = edge.second;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    for(auto node : adj){
        //sort(begin(node.second),end(node.second));
    //    cout<<node.first <<" -> ";
        node.second.sort();
        adj[node.first] = node.second;
//         for(int v : node.second)
//             cout<<v<<" ";
//         cout<<"\n";
//     
    }
    
    for(int i = 0 ; i < vertex ; i++){
        if(!visited[i])
        {
            BFSHelper(i,adj,visited,res);
        }
    }
    
    return res;
}

