#include<bits/stdc++.h>
using namespace std;



class WeightedQuickUnion{
public:    
    WeightedQuickUnion(int d){
        n = d;
        id.resize(n,0);
        size.resize(n,1);
        for(int i = 0 ; i < n ; i++){
            id[i] = i;
        }
    }

    void Qunion(int p,int q){
        if(isConnected(p,q))
            return;
        int proot = root(p);
        int qroot = root(q);

        if(size[proot] <= size[qroot]) { 
            id[proot] = qroot;  
            size[qroot] += size[proot]; 
        }else{
            id[qroot] = proot;
            size[proot] += size[qroot];
        }
    }

    int root(int p){
        while(id[p] != p){
            p = id[p];
        }
        return p;
    }

    bool isConnected(int p,int q){
        return root(p)==root(q);
    }

    void printRootAndSize(){
        cout<<"Node = ";
        for(int i = 0 ; i < n ; i++){
            cout<<i <<" ";
        }
        cout<<"\n";
        cout<<"  id = ";
        for(int i = 0 ; i < n ; i++){
            cout<<id[i] <<" ";
        }
        cout<<"\n";
        cout<<"size = ";
        for(int i = 0 ; i < n ; i++){
            cout<<size[i] <<" ";
        }
        cout<<"\n";
    }
private:
    int n;
    vector<int> id;   // pointer to parent
    vector<int> size;
};


int main(){

    WeightedQuickUnion s(10);
	s.Qunion(2,9);
	s.Qunion(3,4);
	s.Qunion(4,9);
	s.Qunion(6,5);
    s.Qunion(3,5);
    s.printRootAndSize();
    cout<<"is 5->6 : "<<boolalpha<<s.isConnected(5,6)<<"\n";
    cout<<"is 8->9 : "<<boolalpha<<s.isConnected(8,9)<<"\n";
    cout<<"is 3->1 : "<<boolalpha<<s.isConnected(3,1)<<"\n";
    cout<<"is 9->6 : "<<boolalpha<<s.isConnected(9,6)<<"\n";
}