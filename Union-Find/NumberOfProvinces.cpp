// https://leetcode.com/problems/number-of-provinces/

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    void Qunion(int p,int q){
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
    
    int find(int p){
        if(parent[p]==p)
            return p;
        else
            return parent[p] = find(parent[p]);
    }
    
    
    int count(int n){
        int ans = 0;
        for(int i = 0 ; i < n ;i++ ){
            if(parent[i]==i)
                ans++;
        }
        return ans;
    }
    
    int findCircleNum(vector<vector<int>>& adj) {
        parent.resize(200);
        size.resize(200,1);
        for(int i = 0 ; i < 200 ; i++){
            parent[i] = i;
        }
        
        for(int i = 0 ; i < adj.size() ; i++){
            for(int j = 0 ; j < adj[0].size() ; j++){
                if(adj[i][j])
                    Qunion(i,j);
            }
        }
        
        return count(adj.size());
        
    }
    vector<long> size;
    vector<int> parent;
};