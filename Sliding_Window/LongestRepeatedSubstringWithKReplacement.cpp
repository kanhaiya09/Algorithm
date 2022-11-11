#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/longest-repeating-character-replacement/

/*
You are given a string s and an integer k. 
You can choose any character of the string and change it to any other 
uppercase English character. You can perform this operation at most k 
times.

Return the length of the longest substring containing the same letter 
you can get after performing the above operations.

Input: s = "ABAB", k = 2
Output: 4
Explanation: Replace the two 'A's with two 'B's or vice versa.

Input: s = "AABABBA", k = 1
Output: 4
Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
The substring "BBBB" has the longest repeating letters, which is 4.


*/

int characterReplacement(string s, int k) {
    int ans = INT_MIN;
    int i =  0;
    int maxFreq = 0;
    map<char,int> mp;
    for(int j = 0 ; j < s.size() ; j++){
        mp[s[j]]++;
        maxFreq = max(maxFreq, mp[s[j]]);        
        if((j-i+1)-maxFreq > k)  // we don't have to update maxfreq ?
        {
            mp[s[i]]--;
            i++;
        }
        
        ans = max(ans,j-i+1);
    }
    
    return ans;
}
