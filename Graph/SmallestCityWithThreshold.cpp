// https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/

#include<bits/stdc++.h>
using namespace std;


int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
    vector<vector<int>> dist(n,vector<int>(n,1e6));
    for(auto edge : edges){
        int u = edge[0];
        int v = edge[1];
        int w = edge[2];
        dist[u][v] = w;
        dist[v][u] = w;
        dist[u][u] = 0;
        dist[v][v] = 0;
    }

    for(int k = 0 ; k < n ;k++){
        for(int i = 0 ; i < n; i++){
            for(int j = 0 ; j < n ; j++){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);       
            }
        }
    }
    int mx = n;
    int ans = 0;
    for(int i = 0 ; i < n ; i++){
        int cnt = 0;
        for(int j = 0 ; j < n ; j++){
            if(dist[i][j]<=distanceThreshold){
                cnt++;
            }
        }
        mx = min(mx,cnt);
        if(cnt<=mx)
            ans = i;
    }

    return ans;
}