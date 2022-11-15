// https://leetcode.com/problems/longest-substring-without-repeating-characters/

#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string sh) {
    int ans = 0;
    unordered_map<char,int> mp;
    int i = 0 ;
    for(int j = 0 ; j < sh.size() ; j++){
        //calculation
        char ch = sh[j];
        mp[ch]++;
        
        //extract ans
        if(mp.size() == j-i+1){  // if map size is equal to window size
            ans = max(ans,j-i+1);
        }
        
        // if(mp.size()<j-i+1) // that means window contains duplicate elements
        // hence shrink
        if(mp.size()<j-i+1){
            char ch = sh[i];
            mp[ch]--;
            if(mp[ch]==0)
                mp.erase(ch);
            i++;
        }
    }
    return ans;
}
