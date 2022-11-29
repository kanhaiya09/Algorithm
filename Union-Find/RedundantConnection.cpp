// https://leetcode.com/problems/redundant-connection/

#include<bits/stdc++.h>
using namespace std;

class QuickFind{
 public:   
    QuickFind(){
        id.resize(1001);
        for(int i = 0 ; i < 1001 ; i++){
            id[i] = i;
        }
    }
    
    bool isConnected(int p,int q){
        return id[p]==id[q];
    }
    
    void connect(int p,int q){
        int pid = id[p];
        int qid = id[q];
        
        for(int i = 0 ; i < 1001; i++){
            if(id[i]==pid)
                id[i] = qid;
        }
    }
    
    vector<int> id;
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> ans(2,0);
        QuickFind q;
        for(auto edge : edges){
            if(!q.isConnected(edge[0],edge[1])){
                q.connect(edge[0],edge[1]);
            }else{
                ans[0] = edge[0];
                ans[1] = edge[1];
            }
        }
        return ans;
    }
};