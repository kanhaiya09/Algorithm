//https://practice.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) {
    queue<int> q;
    int i = 0 ;
    vector<ll> out;
    
    for(int j = 0 ; j < N ; j++){
        
        //calculate
        if(A[j]<0){
            q.push(A[j]);
        }
        
        
        //check sliding windows condition
        if(j-i+1==K){
            //extract ans
            if(!q.empty()){
                int ans = q.front();
                out.push_back(ans);
            }else{
                out.push_back(0);
            }
            
            //slide window 
            if(A[i]<0)
                q.pop();
            i++;
        }
    }
    return out;
 }