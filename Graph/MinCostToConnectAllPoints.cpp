// https://leetcode.com/problems/min-cost-to-connect-all-points/description/

#include <bits/stdc++.h>
using namespace std;

struct Node{
    int u,v,cost;
    Node(int x,int y,int c):u(x),v(y),cost(c){

    }

    bool operator<(const Node&right) const{
        return this->cost>right.cost;
    }
};

class Solution {
public:
    int find(int p){
        if(p==parent[p]) return p;
        else return parent[p] = find(parent[p]);
    }

    void union_(int p,int q){
        int pid = find(p);
        int qid = find(q);

        if(pid == qid) return;

        if(size[pid]<=size[qid]){
            parent[pid] = qid;
            size[qid]++;
        }else{
            parent[qid] = pid;
            size[pid]++;
        }
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        priority_queue<Node> pq;
        int n = points.size();
        parent.resize(n);
        for(int  i = 0 ; i < n ; i++){
            parent[i] = i;
        }
        size.resize(n,1);

        for(int i = 0 ; i < n ; i++){
            for(int j = i+1 ; j < n; j++){
                int dist = abs(points[i][0]-points[j][0]) + abs(points[i][1]-points[j][1]);
                pq.push(Node(i,j,dist));
            }
        }
        int cnt = 0;
        int res = 0;
        while(cnt<n-1){
            auto tp = pq.top();
            pq.pop();

            int u = tp.u;
            int v = tp.v;
            if(find(u) != find(v)){
                res += tp.cost;
                union_(u,v);
                cnt++;
            }
        }
        return res;
    }

    vector<int> parent;
    vector<int> size;
};