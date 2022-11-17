// https://www.geeksforgeeks.org/count-of-substrings-having-all-distinct-characters/



#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

int CountAllSubStringWithoutRepeatingChar(string s){
    unordered_map<char,int> mp;
    int ans = 0;
    int  i = 0;
    for(int j = 0 ;  j < s.size () ; j++){
        //calculate
        char ch = s[j];
        mp[ch]++;

        // condition
        if(mp.size()==j-i+1){  // this means window contains all the unique character
            ans += j-i+1;
        }

        while(mp.size()<j-i+1){ // that means map contains duplicates
            char ch = s[i];
            mp[ch]--;
            if(mp[ch]==0)
                mp.erase(ch);
            i++;
            //why check here ?  because while shrinking window as well 
            // we might get substring who contains all unique character
            if(mp.size()==j-i+1)
                ans += j-i+1;
        }
    }
    return ans;
}

int main(){
    cout<<CountAllSubStringWithoutRepeatingChar("abcd")<<"\n";
    cout<<CountAllSubStringWithoutRepeatingChar("abba")<<"\n";
    cout<<CountAllSubStringWithoutRepeatingChar("aabcbcdbca")<<"\n";
}