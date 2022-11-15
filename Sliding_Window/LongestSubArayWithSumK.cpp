#include <bits/stdc++.h>
using namespace std;

// This will work for non negative integer arrays only
int lenOfLongSubarr(int A[],  int N, int K) 
{ 
    // Complete the function
    int ans = 0;
    int i = 0 ;
    int sum = 0;
    for(int j = 0 ; j < N ; j++){
        //calculation 
        sum += A[j];
        //condition
        cout<<sum <<" ";
        if(sum == K){
            ans = max(ans,j-i+1);
        }
        //shrink
        while(sum>K){
            sum -= A[i];
            i++;
        }
    }
    return ans;
    
} 
