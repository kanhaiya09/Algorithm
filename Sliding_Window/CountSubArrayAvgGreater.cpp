// https://leetcode.com/problems/number-of-sub-arrays-of-size-k-and-average-greater-than-or-equal-to-threshold/


#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

int numOfSubarrays(vector<int>& arr, int k, int threshold) {
    int i = 0 ; 
    int cnt = 0;
    long sum = 0;
    for(int j =0 ;  j < arr.size() ; j++){
        sum += arr[j];
        
        if(j-i+1==k){
            if(sum/k >= threshold)
                cnt++;
            sum -= arr[i];
            i++;
        }
    }
    return cnt;
}