#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>

using namespace std;
template <typename T>
class Graph{
public:

    Graph(bool directed = false){
        isDirected = directed;
    }

    Graph(int n, bool directed){
        this->n = n;
        isDirected = directed;
        //adj.resize(n);
    }
   
    unordered_map<T,list<T>> adj;
    //vector<list<T>> adj;

    void addEdge(T u,T v, bool isDirected = false){
        adj[u].push_back(v);
        if(isDirected)
            return;
        else
            adj[v].push_back(u);
    }

    void printAdjList(){
        for(auto adjList : adj)
        {
            cout<< adjList.first<<" -> ";
            for(auto nodes : adjList.second){
                cout<<nodes <<",";
            }
            cout<<"\n";
        }
    }

    bool isDirected = false;
    int n; // number of nodes
};


int main(){

    int n;
    cout<<"Enter numbers of nodes : ";
    cin>>n;

    int m;
    cout<<"Enter numbers of edges : ";
    cin>>m;

    Graph<int> g;
    int u,v;
    for(int i = 0 ; i < m ; i++){
        cin>>u>>v;
        g.addEdge(u,v);
    }
    
    g.printAdjList();

}