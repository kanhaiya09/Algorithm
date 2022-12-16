//  https://leetcode.com/problems/sort-colors/

#include <bits/stdc++.h>
using namespace std;

void sortColors(vector<int>& nums) {
    int zero = 0;
    int two = nums.size()-1;
    int i = 0;
    while(i<=two){
        if(nums[i]==0){
            swap(nums[i],nums[zero]);
            zero++;
            i++;
        }else if(nums[i]==2){
            swap(nums[i],nums[two]);
            two--;   
        }else if(nums[i]==1)
            i++;
    }
}