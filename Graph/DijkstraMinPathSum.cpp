// https://practice.geeksforgeeks.org/problems/minimum-cost-path3833/1?

#include <bits/stdc++.h>
using namespace std;

struct Node{
    int x,y,cost;
    Node(int x,int y,int c): x(x),y(y),cost(c)
    {}
    
    bool operator<(const Node& rhs) const{
        return cost > rhs.cost;
    }
};

class Solution
{
    public:
    //Function to return the minimum cost to react at bottom
	//right cell from top left cell.
    int minimumCostPath(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        
        vector<vector<int>> dist(n,vector<int>(n,1e9));
        dist[0][0] = grid[0][0];
        
        priority_queue<Node>pq;
                            
        pq.push(Node(0,0,dist[0][0]));
        
        int dir[5] = {-1,0,1,0,-1};
        
        while(!pq.empty()){
            auto tp = pq.top();
            pq.pop();
            
            int tot = tp.cost;
            int r = tp.x;
            int c = tp.y;
            
            
            if(r==n-1 and c==n-1)
                return tot;
                
                
            for(int i = 0 ;  i < 4 ; i++){
                int nr = r + dir[i];
                int nc = c + dir[i+1];
                
                if(nr>=0 and nr <n and nc>=0 and nc < n){
                    int newDist = tot + grid[nr][nc];
                    if(newDist < dist[nr][nc]){
                        dist[nr][nc] = newDist;
                        pq.push(Node(nr,nc,dist[nr][nc]));
                    }
                }
            }
        }
        
        return 0;
        
    }
};