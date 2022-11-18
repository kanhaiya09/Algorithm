// https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/

#include <bits/stdc++.h>
using namespace std;


static bool myCmp(vector<int>& p1,vector<int>& p2 ){
    return p1[1]<p2[1];
}

int findMinArrowShots(vector<vector<int>>& points) {
    sort(begin(points),end(points),myCmp);
    int ans = 1;
    int cnt = 1;
    int end = points[0][1];
    for(int i = 1; i < points.size() ; i++){
        if(points[i][0]>end){
            ans++;
            end = points[i][1];
        }else if(points[i][0]==end and cnt<2){
            cnt++;
            if(cnt==2)
                cnt = 1;
        }
    }
    return ans;
}