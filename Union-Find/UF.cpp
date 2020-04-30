#inclue<bits/stdc++.h>
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
			this.n = n;
			id = new int[n];
			for(int i = 0 ; i < n;i++)
				id[i] = i;        // they are all different component initially.
		}
		
		
		//QuickFind : check id[p]==id[q]
		bool find(int p,int q){
			return id[p]==id[q];
		}
		
		// union : get the id of p and id of q.replace all occurence of id of p with id of q
		void union(int p,int q){
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
	
		int count()
		{
		}
	private:
		int n;
		int *id;
};
