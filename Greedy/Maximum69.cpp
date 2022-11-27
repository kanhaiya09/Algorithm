// https://leetcode.com/problems/maximum-69-number/

#include <bits/stdc++.h>
using namespace std;

int maximum69Number (int num) {
    string s = to_string(num);
    for(int i = 0 ; i < s.size() ; i++){
        if(s[i]=='6'){
            s[i]= '9';
            break;
        }
    }
    return stoi(s);
} 