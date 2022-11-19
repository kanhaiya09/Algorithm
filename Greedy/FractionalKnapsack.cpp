// https://practice.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1

#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


struct sortByProfitWeight{
    bool operator()(Item& l,Item&r){
        return (double)l.value/(double)l.weight < (double)r.value/(double)r.weight; 
    }
};

double fractionalKnapsack(int W, Item arr[], int n)
{
    priority_queue<Item,vector<Item>,sortByProfitWeight> pq;
    for(int i = 0 ; i < n ; i++){
        pq.push(arr[i]);
    }
    /*cout<<"size : "<<pq.size() <<"\n";
    while(!pq.empty()){
        Item t = pq.top();
        cout<<t.value <<" " <<t.weight<<"\n";
        pq.pop();
    }
    cout<<"Pq size : " <<pq.size()<<"\n";
    */
    double ans = 0;
    while(!pq.empty() and W>0){
        Item t = pq.top();
        pq.pop();
        if(W-t.weight<0){
            //cout<<"ans = " <<ans<<"\n"; 
            ans += ((double)t.value/(double)t.weight)*(W);
            break;
        }else{
            //cout<<"In else block\n";
            ans += t.value;
            W -= t.weight;
        }
        //cout<<"ans = " <<ans<<"\n";
        //cout<<"rem = " <<W<<"\n";
    }
    return ans;
}

int main(){
    int n = 3;
    int values[] = {60,100,120};
    int weight[] = {10,20,30};
    Item items[3];
    for(int i =0 ; i < n ; i++){
        items[i] = {values[i],weight[i]};
    }

    int W = 50;
    cout<<fractionalKnapsack(W,items,n);
}