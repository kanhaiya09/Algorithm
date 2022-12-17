//  https://www.codingninjas.com/codestudio/problems/walls-and-gates_1092887

#include <bits/stdc++.h>
#define INF 2147483647

using namespace std;
vector<vector<int>> wallsAndGates(vector<vector<int>> &a, int n, int m) {
    // Write your code here.
    queue< pair<int,int> > q;
    //push all gates to bfs queue
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if(a[i][j]==0){
                q.push({i,j});
            }
        }
    }
    
    //start bfs traversal
    int dir[5] = {-1,0,1,0,-1};
    int dist = 0;
    while(!q.empty()){
        int size = q.size();
        dist++;
        while(size--){
            auto top = q.front();
            int x = top.first;
            int y = top.second;
            q.pop();
            for(int i = 0 ; i < 4 ; i++){
                int nx = x + dir[i];
                int ny = y + dir[i+1];
                if(nx>=0 and nx< n and ny>=0 and ny<m and a[nx][ny]==INF){
                    a[nx][ny] = dist;
                    q.push({nx,ny});
                }
            }
        }
    }
    return a;
   
}