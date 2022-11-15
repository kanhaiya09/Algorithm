// https://leetcode.com/problems/sliding-window-maximum/

#include <bits/stdc++.h>
using namespace std;


vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> q;
    vector<int> ans;
    int i = 0 ;
    for(int j = 0 ;  j < nums.size() ; j++){
        // calculation
        while(!q.empty() and nums[j]> q.back()){
            q.pop_back();
        }
        q.push_back(nums[j]);
        
        // sliding window condition
        if(j-i+1==k){
            
            //extract answer
            ans.push_back(q.front());
            
            //undo calulation
            if(nums[i]==q.front()){
                q.pop_front();
            }
            //slide window
            i++;
        }
        
    }
    return ans;
}