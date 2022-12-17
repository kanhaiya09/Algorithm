// https://leetcode.com/problems/number-of-operations-to-make-network-connected/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        parent.resize(n);
        size.resize(n,1);

        for(int i = 0 ; i < n ; i++){
            parent[i] = i;
        }

        int redundant = 0;
        for(auto edge : connections){
            int u = edge[0];
            int v = edge[1];

            if(find(u)==find(v)){
                redundant++;
            }else{
                union_(u,v);
            }
        }

        int nc = 0;
        for(int i = 0 ; i < n ; i++){
            if(i==parent[i])
                nc++;
        }

        if(redundant<nc-1)
            return -1;
        else
            return nc-1;
    }

    int find(int p){
        if(p==parent[p]) return p;
        else{
            int res = find(parent[p]);
            parent[p] = res;
            return res;
        }
    }

    void union_(int p,int q){
        int pid = find(p);
        int qid = find(q);
        if(size[pid]<=size[qid]){
            parent[pid] = qid;
            size[qid]++;
        }else{
            parent[qid] = pid;
            size[pid]++;
        }

    }

    vector<int> parent;
    vector<int> size;
};