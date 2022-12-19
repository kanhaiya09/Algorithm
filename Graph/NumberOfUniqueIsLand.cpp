//  https://practice.geeksforgeeks.org/problems/number-of-distinct-islands/1

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void dfs(int r,int c,vector<vector<int>>& grid,vector<pair<int,int>>&path , int r0,int c0){
        //visit grid by making it to 0
        grid[r][c] = 0;
        
        //add bash path in path
        path.push_back({r-r0,c-c0});
        
        int dir[5] = {-1,0,1,0,-1};
        
        for(int i = 0 ; i < 4 ; i++){
            int nr = r + dir[i];
            int nc = c + dir[i+1];
            
            if(nr>=0 and nr< grid.size() and nc>=0 and nc<grid[0].size() and grid[nr][nc]==1){
               dfs(nr,nc,grid,path,r0,c0);
            }            
        }
    }
  
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        set< vector<pair<int,int>> > st;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j]==1){ // found island
                    vector<pair<int,int> > path;
                    dfs(i,j,grid,path,i,j);
                    st.insert(path);
                }
            }
        }
        
        return st.size();
    }
};