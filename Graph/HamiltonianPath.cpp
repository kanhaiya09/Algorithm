// Hamiltonian Path is a path in an undirected or directed graph that visits every vertex exactly once

#include <bits/stdc++.h>
using namespace std;

class Graph{
public:
    Graph(int n){
        vertex = n;
        adj.resize(n);
        visited.resize(n,false);
    }

    void addEdge(int u,int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void printHamiltonianPath(int s,int& cnt,vector<int>& path){
        visited[s] = true;
        path.push_back(s);
        cnt++;
        if(cnt==vertex){
            printPath(path);       
        }
        for(int v : adj[s]){
            if(!visited[v]){
                printHamiltonianPath(v,cnt,path);
            }
        }
    
        visited[s] = false;
        path.pop_back();
        cnt--;
    }

    void printPath(vector<int> &path){
        int n = path.size();
        for(int i = 0 ; i < n-1 ; i++){
            cout<<path[i] <<" -> ";
        }
        cout<<path[n-1] <<"\n";
    }

private:
    vector<bool> visited;
    vector<vector<int>> adj;
    int vertex;
};



int main(){
    Graph g(7);
    g.addEdge(0,1);
    g.addEdge(0,3);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(2,5);
    g.addEdge(4,5);
    g.addEdge(5,6);
    g.addEdge(4,6);
    vector<int> path;
    int cnt= 0;
    g.printHamiltonianPath(0,cnt,path);
}