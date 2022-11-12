// https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/

#include <bits/stdc++.h>
using namespace std;


bool isVowel(char ch){
    return ch=='a' or ch=='e' or ch=='i' or ch=='o' or ch=='u';
}

int maxVowels(string s, int k) {
    int ans = INT_MIN;
    int i = 0;
    int cnt = 0;
    for(int j = 0 ; j < s.size() ; j++){
        if(isVowel(s[j]))
            cnt++;
        
        if(j-i+1==k){
            ans = max(ans,cnt);
            if(isVowel(s[i]))
                cnt--;
            i++;
        }
    }
    return ans;
}

int main(){


    
}