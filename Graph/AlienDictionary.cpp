// https://practice.geeksforgeeks.org/problems/alien-dictionary/1

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    string findOrder(string dict[], int N, int K) {
        vector<vector<int>> adj(K);
        
        for(int i = 0 ; i < N-1 ;i++){
            string s1 = dict[i];
            string s2 = dict[i+1];
            int len = min(s1.size(),s2.size());
            for(int i = 0 ; i < len ; i++){
                if(s1[i] != s2[i]){
                    adj[s1[i]-'a'].push_back(s2[i]-'a');
                    break;
                }
            }
        }
        
        vector<int> indeg(K,0);
        vector<int> topOrder;
        for(int i = 0 ; i < K ; i++){
            for(int v : adj[i]){
                indeg[v]++;
            }
        }
        
        queue<int> q;
        for(int i = 0 ; i < K ; i++){
            if(indeg[i]==0)
                q.push(i);
        }
    
        while(!q.empty()){
            int tp = q.front();
            q.pop();
            topOrder.push_back(tp);
            for(int v : adj[tp]){
                indeg[v]--;
                if(indeg[v]==0)
                    q.push(v);
            }
        }
    
    
        string ans = "";
        for(int n : topOrder){
            ans += char(n+'a');
        }
        
        return ans;
    }
};
