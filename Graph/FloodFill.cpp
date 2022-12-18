// https://leetcode.com/problems/flood-fill/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
        

        queue< pair<int,int> > q;
        q.push({sr,sc});
        int srcColor = image[sr][sc];
        image[sr][sc] = color;
        
        if(srcColor==color)
            return image;
        int dir[5] = {-1,0,1,0,-1};
        
        while(!q.empty()){
            auto [r,c] = q.front();
            q.pop();      
            cout<<r<<" "<<c <<"\n";    
            for(int i = 0 ; i < 4  ; i++){
                int nr = r + dir[i];
                int nc = c + dir[i+1];
                if( nr>=0 && nr < m && nc>=0 && nc< n && image[nr][nc]==srcColor){
                    image[nr][nc] = color;
                    q.push({nr,nc});
                }
            }
        }

        return image;
    }
};