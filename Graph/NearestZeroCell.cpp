//  https://leetcode.com/problems/01-matrix/

#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector< vector<int> > ans(m, vector<int>(n,-1));
        queue<int> q;
        for(int i = 0 ; i < m ; i++){
            for(int  j = 0 ; j < n ; j++){
                if(mat[i][j]==0){
                    int id = i*n+j;
                    q.push(id);
                    ans[i][j] = 0;  // make all 0's visited
                }
            }
        }
        
        vector<int> dir = {-1,0,1,0,-1}; 
        int dist = 1;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                int top = q.front();
                q.pop();
               // cout<<top <<" ";
                int currX = top/n;
                int currY = top%n;
                for(int i = 0 ; i < 4 ; i++){
                    int nextX = currX + dir[i];
                    int nextY = currY + dir[i+1];
                    if(nextX >=0  and nextX <m  and nextY>=0  and nextY< n and ans[nextX][nextY]==-1)  // not visited and valid cell
                    {
                        //cout<<currX <<"," << currY <<" ==> pushed " << nextX <<"," <<nextY <<"\n";
                        q.push(nextX*n+nextY);
                        ans[nextX][nextY] = dist;
                    }
                }
            }
            dist++;
        }
        return ans;
    }
};
