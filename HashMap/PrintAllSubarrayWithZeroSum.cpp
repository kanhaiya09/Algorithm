// print all subarray with sum equals to zero

#include<bits/stdc++.h>
using namespace std;

/*
input      :        6   -1  -3  4   -2  2   4    6  -12   2
prefixSum  :  0     6   5   2   6   4   6   10  16   4    6  
index      : -1     0   1   2   3   4   5   6   7    8    9
map => map<int, vector<int>> => map of prefix sum and vector of index 
sum-> indexlist
0  -> [-1 ]
6  -> [ 0 ]
      [ 0 , 3 ]
        1 -> 3    //out.push_back()
      [ 0 , 3 , 5]
        1 -> 5   //out.push_back()
        4 -> 5   //out.push_back()
      [ 0 , 3 , 5 , 9]
        1 -> 9   //out.push_back()
        4 -> 9   //out.push_back()
        6 -> 9   //out.push_back()
5  -> [ 1 ]
2  -> [ 2 ]
4  -> [ 4 ]
      [ 4 , 8]
        5 -> 8   //out.push_back()
10 -> [ 6 ]
16 -> [ 7 ]
*/


void printSubarrayWithZeroSum(vector<int> &v){
    int sum = 0 ;
    vector<pair<int,int>> output;
    map<int,vector<int>> mp;
    mp[sum] = {-1};
    for(int i = 0 ; i < v.size() ; i++){
        sum += v[i];
        if(mp.find(sum)==mp.end()){
            mp[sum] = {i};
        }else{
            for(int j = 0 ; j < mp[sum].size() ; j++){
                output.push_back({mp[sum][j]+1,i});
            }
            mp[sum].push_back(i);
        }   
    }
    for(int i = 0 ; i < output.size() ; i++){
        auto itr = output[i];
        cout << "0 = ";
        for(int j = itr.first ; j <= itr.second ; j++){
            cout<< v[j] <<" + ";
        }
        cout<<" 0\n";
    }
}


int main(){
    vector<int> v = { 6, -1, -3, 4, -2, 2, 4, 6, -12, 2 };
    printSubarrayWithZeroSum(v);
    return 0;
}
