#include<bits/stdc++.h>
using namespace std;

/*
//Dynamic connectivity
//API for Union find algorithm.

class UF{
		  UF(int n);                 // initialize union -find ds with N object (0 to N-1)
	void  union(int p,int q);        // add connection between p and q;
	bool  connected(int p,int q);	 // are p and q same component
	int   find(int p)  ;             // component identifier for p (0 to N-1)
	int   count();                   // number of connected component.
};
*/

class QuickUnion{
public:    
    QuickUnion(int d){
        n = d;
        id.resize(n,0);
        for(int i = 0 ; i < n ; i++){
            id[i] = i;
        }
    }

    void Qunion(int p,int q){
        if(isConnected(p,q))
            return;

        // why not id[p] = id[q] ??    
        int proot = root(p);
        int qroot = root(q);
        id[proot] = qroot;
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

    void printRoots(){
        for(int i = 0 ; i < n ; i++){
            cout<<id[i]<<" ";
        }
        cout<<"\n";
    }
private:
    int n;
    vector<int> id;   // pointer to parent
};


int main(){

    QuickUnion s(10);
	
	/*s.Qunion(0,1);
	s.Qunion(3,4);
	s.Qunion(4,2);
	s.Qunion(2,1);
	s.Qunion(6,5);
	s.Qunion(5,7);
    */
    s.Qunion(2,9);
	s.Qunion(3,4);
	s.Qunion(4,9);
	s.Qunion(6,5);
    s.Qunion(3,5);
    s.printRoots();
    cout<<"is 5->6 : "<<boolalpha<<s.isConnected(5,6)<<"\n";
    cout<<"is 8->9 : "<<boolalpha<<s.isConnected(8,9)<<"\n";
    cout<<"is 3->1 : "<<boolalpha<<s.isConnected(3,1)<<"\n";
    cout<<"is 9->6 : "<<boolalpha<<s.isConnected(9,6)<<"\n";
}