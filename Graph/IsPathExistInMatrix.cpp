// https://www.geeksforgeeks.org/check-possible-path-2d-matrix/
// https://practice.geeksforgeeks.org/problems/find-whether-path-exist5238/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    
    bool dfs(int i,int j,int n,int m,vector<vector<int>>& grid){
        if(i<0 or i>=n or j<0 or j>=m or visited[i][j]==true or grid[i][j]==0)
            return false;
            
        if(grid[i][j]==2)
            return true;
            
        visited[i][j] = true;
        
        return dfs(i+1,j,n,m,grid) or dfs(i-1,j,n,m,grid) or dfs(i,j+1,n,m,grid) or dfs(i,j-1,n,m,grid);
        
    }
    
    //Function to find whether a path exists from the source to destination.
    bool is_Possible(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        int m = grid[0].size();
        visited.resize(n,vector<bool>(m,false));
        for(int i = 0 ; i < n ; i++){
            for(int j = 0; j < m ; j++){
                if(grid[i][j]==1){  // found source apply dfs
                    if(dfs(i,j,n,m,grid))
                        return true;
                }
            }
        }
        return false;
    }
    
    vector<vector<bool>> visited;
};
