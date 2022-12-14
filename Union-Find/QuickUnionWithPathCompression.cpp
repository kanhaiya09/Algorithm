#include <bits/stdc++.h>
using namespace std;



class QUWithPathCompression{
public:
    QUWithPathCompression(int n){
        this->n = n;
        parent.resize(n);
        for(int i = 0 ;i < n ; i++){
            parent[i] = i;
        }
    }

    int find(int p){
        if(p==parent[p])
            return p;
        
        else{
            parent[p] = find(parent[p]);
            return parent[p];
        }
    }

    void union_(int p ,int q){
        int proot = find(p);
        int qroot = find(q);

        if(proot==qroot)
            return;

        parent[proot] = qroot;
    }

    bool isConnected(int p,int q){
        return find(p)==find(q);
    }

    void printParent(){
        cout<<std::left<<setw(10) <<"Node : ";
        for(int i = 0 ; i < n ; i++){
            cout<<i<<" ";
        }
        cout<<"\n";
        cout<<std::left<<setw(10) <<"Parent :";
        for(int i = 0 ; i < n ; i++){
            cout<<parent[i]<<" ";
        }
        cout<<"\n";
    }
private:
    int n;
    vector<int> parent;
};

int main(){
    
    QUWithPathCompression q(5);
    q.union_(4,3);
    q.union_(3,2);
    q.union_(2,1);
    q.union_(1,0);
    q.printParent();

    cout<<"4-->0 : "<<boolalpha<<q.isConnected(4,0)<<"\n";
    q.printParent();
}