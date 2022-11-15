// https://leetcode.com/problems/minimum-window-substring/

/*

Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" 
             includes 'A', 'B', and 'C' from string t.

*/

#include <bits/stdc++.h>
using namespace std;

string minWindow(string s, string t) {     
    unordered_map<char,int> mp;
    for(char ch : t){
        mp[ch]++;
    }
    int cnt = mp.size();
    int ans = INT_MAX;
    int i = 0;
    int st = 0;
    for(int j = 0 ;j < s.size() ; j++){
        //calculation
        char ch = s[j];
        if(mp.find(ch) != mp.end()){
            mp[ch]--;
            if(mp[ch]==0)
                cnt--;
        }
        
        //condition
        while(cnt==0 ){
            // cout<<i <<" " <<j <<"\n";
            //extract answer
            if(j-i+1<ans)
            {
                ans = j-i+1;
                st = i;
            }
            //undo calculation
            char ch = s[i];
            if(mp.find(ch) != mp.end()){
                mp[ch]++;
                if(mp[ch]==1)
                    cnt++;
            }
            
            //slide window
            i++;
        }
    }
    if(ans==INT_MAX)
        return "";
    else 
        return s.substr(st,ans);
}