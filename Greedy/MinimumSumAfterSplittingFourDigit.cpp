// https://leetcode.com/problems/minimum-sum-of-four-digit-number-after-splitting-digits/


#include <bits/stdc++.h>
using namespace std;

int minimumSum(int num) {
    vector<int> n(4,0);
    int i = 0;
    while(num>0){
        n[i] = num%10;
        num /= 10;
        i++;
    }
    sort(begin(n),end(n));
    int new1 = n[0]*10+n[3];
    int new2 = n[1]*10+n[2];
    return new1+new2;
}