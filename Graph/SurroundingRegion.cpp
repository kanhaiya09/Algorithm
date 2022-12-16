//  https://leetcode.com/problems/surrounded-regions/

#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        queue<int> q;
        
        // add all border 'O' in queue
        for(int i = 0 ; i < m ; i++) // check 1st and last column
        {
            //1st column
            if(board[i][0]=='O'){
                int id = i*n+0;
                q.push(id);
            }
            //last column
            if(board[i][n-1]=='O'){
                int id = i*n+n-1;
                q.push(id);
            }
        }
        
        for(int i = 0 ; i < n ; i++) // check 1st and last row
        {
            //1st row
            if(board[0][i]=='O' and i>0){
                int id = i;
                q.push(id);
            }
            //last row
            if(board[m-1][i]=='O' and i>0){
                int id = (m-1)*n+i;
                q.push(id);
            }
        }
    
        int dir[5] = {-1,0,1,0,-1};
        
        // for all borders '0' ,its connected '0' will also remain '0' so mark is safe like 'Z'
        // this marking will also work as visited matrix as well
        while(!q.empty()){
            int id = q.front();
            q.pop();
            
            int currX = id / n;
            int currY = id % n;
            
            board[currX][currY] = 'Z' ; // we will change this 'Z' back to 'O'
            
            for(int i = 0 ; i < 4 ; i++){
                
                int newX = currX + dir[i];
                int newY = currY + dir[i+1];
                
                if(newX>=0 and newY>=0 and newX < m and newY <n and board[newX][newY]=='O'){
                    int id = newX*n+newY;
                    q.push(id);
                }
            }
        }
        
        
        for(int i = 0 ;i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(board[i][j]=='Z'){
                    board[i][j] = 'O';
                }else if(board[i][j]=='O'){
                    board[i][j] = 'X';
                }
            }
        }
        
    }
};