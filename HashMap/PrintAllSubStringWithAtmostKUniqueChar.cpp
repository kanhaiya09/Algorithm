#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

void PrintAllSubStringWithAtmostKUniqueChar(string s,int K){
    unordered_map<char,int> mp;
    vector<pair<int,int>> out; 
    int ans = 0;
    int  i = 0;
    for(int j = 0 ;  j < s.size () ; j++){
        //calculate
        char ch = s[j];
        mp[ch]++;

        // condition
        if(mp.size()<=K){  // this means window contains all the unique character
            out.push_back({i,j-i+1});
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
            {
                out.push_back({i,j-i+1});
                ans += j-i+1;
            }
        }
    }

    int cnt = 0;
    for(auto itr : out){
        int start = itr.first;
        for(int len = 1 ; len <= itr.second ; len++){
            cout<< s.substr(start,len)<<"\n";
            cnt++;
        }
    }
    cout<<boolalpha<< (ans==cnt);
}

int main(){
    PrintAllSubStringWithAtmostKUniqueChar("aabcbcdbca",2);
    return 0;
}