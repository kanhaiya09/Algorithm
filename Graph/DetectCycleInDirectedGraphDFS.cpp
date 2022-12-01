// https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1


#include <bits/stdc++.h> 
using namespace std;

enum Color{WHITE,GREY,BLACK};    
// Function to detect cycle in a directed graph.
bool isCyclic(int V, vector<int> adj[]) {
    // code here
    //mark all nodes as WHITE
    vector<int> color(V,WHITE);
    
    for(int i = 0 ; i < V ; i++){
        if(color[i]==WHITE){
            bool ans = dfs(i,color,adj);
            if(ans==true)
                return ans;
        }
    }
    
    return false;
}

bool dfs(int u, vector<int>& color, vector<int> adj[]){
    
    // mark current cell as Grey
    color[u] = GREY;
    
    for(int v : adj[u]){
        if(color[v]==WHITE){
            bool ans = dfs(v,color,adj);
            if(ans==true)
                return true;
        }else{
            if(color[v]==GREY)
                return true;     // found backedge => cycle present 
        }
    }
    
    color[u] = BLACK;
    return false;
}
