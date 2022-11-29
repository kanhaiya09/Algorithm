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


class QuickFindUF{
	public:
		QuickFindUF(int n)
		{
			this->n = n;
			id = new int[n];
			for(int i = 0 ; i < n;i++)
				id[i] = i;        // they are all different component initially.
		}
		
		
		//QuickFind : check id[p]==id[q]
		bool find(int p,int q){
			return id[p]==id[q];
		}
		
		// union : get the id of p and id of q.replace all occurence of id of p with id of q
		void QFunion(int p,int q){
			int idp = id[p];
			int idq = id[q];
			for(int i = 0 ; i < n ;i++)
			{
				if(id[i]==idp)
					id[i] = idq;
			}
		}
		
		int find(int p){
			return id[p];
		}
	
		// returns the number of connected component
		int count()   
		{
			int cnt = 0;
			for(int i = 0 ;i< n ; i++)
			{
				if(id[i]==i)
					cnt++;
			}
			return cnt;
		}
		
	private:
		int n;
		int *id;
};


int main()
{
	QuickFindUF s(8);
	
	s.QFunion(0,1);
	s.QFunion(3,4);
	s.QFunion(4,2);
	s.QFunion(2,1);
	s.QFunion(6,5);
	s.QFunion(5,7);
	
	cout<<s.count();
}
