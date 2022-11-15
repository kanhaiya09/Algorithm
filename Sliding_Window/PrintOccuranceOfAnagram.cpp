// https://practice.geeksforgeeks.org/problems/count-occurences-of-anagrams5839/1

/*

Input:
txt = forxxorfxdofr
pat = for
Output: 3
Explanation: for, orf and ofr appears
in the txt, hence answer is 3.


*/


#include <bits/stdc++.h>
using namespace std;

int search(string pat, string txt) {

    unordered_map<char,int> mp;
    for(char ch : pat){
        mp[ch]++;
    }
    int k = pat.size();
    int cnt = mp.size();
    int i = 0 ;
    int ans = 0;
    vector<string> out;
    
    for(int j = 0 ; j < txt.size() ; j++){
        //calculation
        char ch = txt[j];
        if(mp.find(ch) != mp.end()){
            mp[ch]--;
            if(mp[ch]==0)
                cnt--;
        }
        
        if(j-i+1==k){
            //extract answer
            if(cnt==0){
                ans++;
                out.push_back(txt.substr(i,k));
            }
            
            //undo calculation
            char ch  = txt[i];
            if(mp.find(ch) != mp.end()){
                mp[ch]++;
                if(mp[ch]==1)
                    cnt++;
            }
            
            //slide window
            i++;
        }
        
    }

    for(string s : out){
        cout<<s<<"\n";
    }    

    return ans;
}


int main(){
    cout<<search("for","forxxorfxdofr");
}