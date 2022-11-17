// https://www.geeksforgeeks.org/count-of-all-unique-substrings-with-non-repeating-characters/

#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

void allUniqueSubstringWithoutRepeatingChar(string s){
    set<string> ans;
    for(int i = 0 ; i < s.size() ; i++){
        unordered_set<char> visited;
        for(int j = i ; j < s.size() ; j++){
            char ch = s[j];
            if(visited.find(ch) == visited.end()){
                visited.insert(ch);
                ans.insert(s.substr(i,j-i+1));
            }else
                break;
        }
    }

    for(string tmp : ans){
        cout<<tmp<<",";
    }
    cout<<"\n";
}

int main(){
   allUniqueSubstringWithoutRepeatingChar("abba"); 
   allUniqueSubstringWithoutRepeatingChar("abcd"); 
}

