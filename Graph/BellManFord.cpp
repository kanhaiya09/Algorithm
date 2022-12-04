// https://practice.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/1

#include <bits/stdc++.h> 
using namespace std;

 /*  Function to implement Bellman Ford
    *   edges: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
*/
vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
    vector<int> dist(V,1e8);
    dist[S] = 0;
    for(int i = 1 ; i < V ; i++){
        
        //iterate through all the edge 
        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            
            if(dist[u] != 1e8){  // we have path of edge length i till u 
                if(dist[v]> dist[u] + w)
                {
                    dist[v] = dist[u]+w;
                }
            }
            
        }
        cout<<"Iteration = " <<i <<"\n";
        for(auto n : dist){
            cout<<n <<" ";
        }
        cout<<"\n";
    }
    
    bool negativeCycle = false;
    for(auto edge : edges){
        int u = edge[0];
        int v = edge[1];
        int w = edge[2];
        
        if(dist[u] != INT_MAX){  // we have path of edge length i till u 
            if(dist[v]> dist[u] + w)
            {
                negativeCycle = true;
                break;
            }
        }
    }
    
    if(negativeCycle){
        //vector<int> v(V,-1);
        return {-1};
    }else
        return dist;
}


int main(){
    int V = 4;
    vector<vector<int>>edges;
    int s = 1;


    // edges.push_back({0,1,4});
    // edges.push_back({0,3,5});
    // edges.push_back({2,1,-10});
    // edges.push_back({3,2,3});
    
    // bellman_ford(V,edges,0);
    
    // output : 
    // Iteration = 1
    // 0 4 8 5
    // Iteration = 2
    // 0 -2 8 5
    // Iteration = 3
    // 0 -2 8 5
    

   //changing the edge input order
    edges.push_back({2,1,-10});
    edges.push_back({3,2,3});
    edges.push_back({0,1,4});
    edges.push_back({0,3,5});
    bellman_ford(V,edges,0);
    /*
    Iteration = 1
    0 4 100000000 5
    Iteration = 2
    0 4 8 5
    Iteration = 3
    0 -2 8 5
    */

}