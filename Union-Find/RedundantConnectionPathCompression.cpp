// https://leetcode.com/problems/redundant-connection/

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int find(int p){
        if(p==parent[p]) return p;
        else return parent[p] = find(parent[p]);
    }
    
    void Qunion(int p,int q){
        int proot = find(p);
        int qroot = find(q);
        
        if(size[proot] <= size[qroot]){
            parent[proot] = qroot;
            size[qroot] += size[proot];
        }else{
            parent[qroot] = proot;
            size[proot] += size[qroot];
        }
    }
    
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        parent.resize(n+1);
        size.resize(n+1);
        for(int i = 1 ; i <= n ;i++){
            parent[i] = i;
            size[i] = 1;
        }
        
        for(auto edge : edges){
            if(find(edge[0])==find(edge[1]))
                return edge;
            else
                Qunion(edge[0],edge[1]);
        }
        
        return {};
    }
    
private:
    vector<int> parent;
    vector<int> size;
};