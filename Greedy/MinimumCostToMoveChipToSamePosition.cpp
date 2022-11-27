// https://leetcode.com/problems/minimum-cost-to-move-chips-to-the-same-position/

#include <bits/stdc++.h>
using namespace std;

int minCostToMoveChips(vector<int>& position) {
    int oddCnt = 0;
    int evenCnt = 0;
    for(int i = 0 ; i < position.size() ; i++){
        if(position[i]%2==0)
            evenCnt++;
        else{
            oddCnt++;     
        }
    }
    return min(evenCnt,oddCnt);
    
}