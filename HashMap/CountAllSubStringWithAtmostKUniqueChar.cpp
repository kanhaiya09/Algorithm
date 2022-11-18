// https://www.geeksforgeeks.org/count-of-substrings-having-all-distinct-characters/



#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

int CountAllSubStringWithAtmostKUniqueChar(string s,int K){
    unordered_map<char,int> mp;
    int ans = 0;
    int  i = 0;
    for(int j = 0 ;  j < s.size () ; j++){
        //calculate
        char ch = s[j];
        mp[ch]++;

        // condition
        if(mp.size()<=K){  // this means window contains all the unique character
            ans += j-i+1;
        }

        while(mp.size()>K){ // that means windows contains more than K unique char , so shrink and check
            char ch = s[i];
            mp[ch]--;
            if(mp[ch]==0)
                mp.erase(ch);
            i++;
            //why check here ?  because while shrinking window as well 
            // we might get substring who contains all unique character
            if(mp.size()<=K)
                ans += j-i+1;
        }
    }
    return ans;
}

int main(){
    cout<<CountAllSubStringWithAtmostKUniqueChar("aabcbcdbca",2);
}