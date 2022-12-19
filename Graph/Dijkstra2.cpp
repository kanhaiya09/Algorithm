// https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1?

#include <bits/stdc++.h>
using namespace std;

//Function to find the shortest distance of all the vertices
//from the source vertex S.
vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
{
    vector<int> dist(V,1e9);
    dist[S] = 0;
    
    set< pair<int,int> > st;
    st.insert({0,S});
    
    while(!st.empty()){
        auto tp = *(st.begin());
        st.erase(st.begin()); //pop
        int d = tp.first;
        int node = tp.second;
        
        for(auto edge : adj[node]){
            int v = edge[0];
            int weight = edge[1];
            if(d + weight < dist[v]){
                if(dist[v] != 1e9)   // means it is already in set {dist[v],v}
                {
                    st.erase({dist[v],v});
                }
                //insert updated dist in set
                st.insert({d + weight,v});
                dist[v] = d + weight;
            }    
        }
        
    }
    return dist;
}