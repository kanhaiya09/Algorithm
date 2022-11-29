// https://leetcode.com/problems/graph-connectivity-with-threshold/


#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    void Qunion(int p,int q){
        int proot = find(p);
        int qroot = find(q);
        parent[proot] = qroot;
    }
    
    int find(int p){
        if(parent[p]==p) return p;
        else return parent[p] = find(parent[p]);   
    }
    
    void print(){
        for(int n : parent){
            cout<<n<<" ";
        }
        cout<<"\n";
    }
    
    vector<bool> areConnected(int n, int threshold, vector<vector<int>>& q) {
        parent.resize(n+1);
        for(int i = 1; i <= n ; i++){
            parent[i] = i;
        }
        
        for(int node = threshold+1 ; node < n ; node++){
            int j = 1;
            int multiples = node*j;
            while(multiples<=n){
                Qunion(multiples,node);
                j++;
                multiples = node*j;
            }
        }
        //print();
        vector<bool> ans(q.size());
        for(int i = 0 ; i < q.size() ; i++){
            ans[i] = (find(q[i][0]) == find(q[i][1]));
        }
        return ans;
    }
    
private:
    vector<int> parent;
    
};