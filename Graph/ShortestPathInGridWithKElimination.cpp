// https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/

#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> rem(m,vector<int>(n,-1));  //will also work as visited array
        queue<vector<int>> q;
        
        q.push({0,0,k});
        rem[0][0] = k;
        int level = 0;
 
        vector<int> dir = {-1,0,1,0,-1};
        while(!q.empty()){
            int size = q.size();
            while(size--){
                vector<int> top = q.front();
                q.pop();
                
                int currX = top[0];
                int currY = top[1];
                int remK = top[2];
                                
                if(currX ==m-1 and currY==n-1)
                    return level;
                
                for(int i = 0 ; i < 4 ; i++){
                    int newX = currX + dir[i];
                    int newY = currY + dir[i+1];
                    
                    if(newX >=0 and newX<m and newY>=0 and newY<n){ //within matrix
                        
                        /*if(grid[newX][newY]==0){ //blank cell
                            if(remK > rem[newX][newY]){
                                q.push({newX,newY,remK});  // don't change remK
                                rem[newX][newY] = remK;    //don't forget to update remK 
                            }
                        }else{
                            if(remK>0 and remK > rem[newX][newY]){
                                q.push({newX,newY,remK-1});  // one K down
                                rem[newX][newY] = remK-1;
                            }
                        }*/

                        int remains = remK- grid[newX][newY];  // because grid[newX][newY] can be either 0 or 1  
                        if(remains>=0 and remains > rem[newX][newY]){
                            q.push({newX,newY,remains});       
                            rem[newX][newY] = remains;
                        }
                        
                    }
                    
                }                
            }
            level++;
        }
        
        return -1;
    }
};
