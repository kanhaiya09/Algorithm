//  https://leetcode.com/problems/max-area-of-island/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    int find(int p){
        if(p == parent[p]) return p;
        else return parent[p] = find(parent[p]);
    }
    
    void union_(int p,int q){
        int pid = find(p);
        int qid = find(q);
        
        if(pid==qid)
            return;
        if(size[pid]<= size[qid]){
            parent[pid] = qid;
            size[qid] += size[pid];
        }else{
            parent[qid] = pid;
            size[pid] += size[qid];
        }
    }
    
    int max_count(){
        int ans = 0;
        for(int i = 0 ; i < size.size() ; i++){
            if(size[i]>ans)
                ans = size[i];
        }
        return ans;
    }
    

    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

            
        int nodes = n*m;  
        parent.resize(nodes);
        size.resize(nodes,1);
        
        for(int i = 0 ; i < nodes ; i++){
            parent[i] = i;
        }
        
        int ans = 0;
        bool flg = false;
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(grid[i][j]==1){
                    ans = 1;
                    //check next col is 1 , if yes merge this(i*n+j) and next col(i*n+j+1) index
                    if(j+1< n and grid[i][j+1]==1){
                        flg = true;
                        union_(i*n+j,i*n+j+1);
                    }
                    //check if down cell is 1, if yes merge this(i*n+j) and down cell((i+1)*n+j)
                    if(i+1<m and grid[i+1][j]==1){
                        flg = true;
                        union_(i*n+j,(i+1)*n+j);
                    }
                }
            }
        }
        
        return flg==false ? ans :max_count();
    }
     vector<int> parent;
     vector<int> size;
    
};