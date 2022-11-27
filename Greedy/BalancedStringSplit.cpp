// https://leetcode.com/problems/split-a-string-in-balanced-strings/

#include <bits/stdc++.h>
using namespace std;

int balancedStringSplit(string s) {
    int cnt = 0;
    int ans= 0;
    for(int i = 0 ; i < s.size() ; i++){
        if(s[i]=='R')
            cnt++;
        else
            cnt--;
        
        if(cnt==0)
            ans++;
    }
    return ans;
}