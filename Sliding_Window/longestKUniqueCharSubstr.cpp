#include <bits/stdc++.h>
using namespace std;
/*
Given a string you need to print the size of the 
longest possible substring that has exactly K unique characters. 
If there is no possible substring then print -1.

Input:
S = "aabacbebebe", K = 3
Output: 7


Input: 
S = "aaaa", K = 2
Output: -1

*/


int longestKSubstr(string s, int k) {
    int i = 0, ans = -1 , n = s.size();
    map<char,int> mp;
    
    for(int j = 0 ; j < n ; j++){
        //calculation
        mp[s[j]]++;
        if(mp.size()==k)
            ans = max(ans,j-i+1);
        while(mp.size()>k){
            mp[s[i]]--;
            if(mp[s[i]]==0){
                mp.erase(s[i]);
            }
            i++;
        }
        
    }
    return ans;        
}


int main(){
    cout<<longestKSubstr("aabacbebebe",3)<<"\n";
    cout<<longestKSubstr("aaaa",2)<<"\n";
}