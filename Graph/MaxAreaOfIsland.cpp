//  https://leetcode.com/problems/max-area-of-island/

#include <bits/stdc++.h> 
using namespace std;

void dfs(int r , int c ,vector<vector<int>>& grid,int& cnt){
    int m = grid.size();
    int n = grid[0].size();
    if(r>=m or c>=n or r<0 or c<0 or grid[r][c] != 1)
        return;
    
    //visit
    grid[r][c] = 2;
    cnt++;
    dfs(r-1,c,grid,cnt);
    dfs(r+1,c,grid,cnt);
    dfs(r,c-1,grid,cnt);
    dfs(r,c+1,grid,cnt);
}

    
int maxAreaOfIsland(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    /*int nodes = max(m,n);  
    parent.resize(nodes);
    size.resize(nodes,0);
    
    for(int i = 0 ; i < nodes ; i++){
        parent[i] = i;
    }
    */
    int ans = 0;
    for(int i = 0 ; i < m ; i++){
        for(int j = 0 ; j < n ; j++){
            if(grid[i][j]==1){
                int cnt = 0;
                dfs(i,j,grid,cnt);
                ans = max(ans,cnt);
            }
        }
    }
    
    return ans;
}