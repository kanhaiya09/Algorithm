// https://leetcode.com/problems/find-center-of-star-graph/


#include <bits/stdc++.h> 
using namespace std;


// find center in star graph
// 1 vertex will be common in all edge :  find that vertex => that's center

int findCenter(vector<vector<int>>& edge) {
    int u = edge[0][0];
    int v = edge[0][1];
    
    int p = edge[1][0];
    int q = edge[1][1];
    
    if(u==p or u==q)
        return u;
    else
        return v;
       
}