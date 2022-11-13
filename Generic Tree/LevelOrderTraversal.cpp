#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    vector<Node*> children;

    Node(int d){
        data = d;
    }
};

void createTree(Node* &root,vector<int> &path){
    stack<Node*> st;
    for(int i = 0 ; i < path.size() ; i++){
        if(path[i]==-1){
            st.pop();
        }else{
            Node* child = new Node(path[i]);
            if(st.empty()){
                root = child;
                st.push(child);
            }else{
                st.top()->children.push_back(child);
                st.push(child);
            }
        }
    }
}

/*
*  e.g.
              10
           /  |  \
        20   30   60
            /  \
           40  50
           /
         100

output : 10 20 30 60 40 50 100
*/    


void traversal(Node* root){
    queue<Node* > q;
    q.push(root);
    while(!q.empty()){
        Node* curr = q.front();
        q.pop();
        cout<<curr->data <<" ";
        for(Node* child : curr->children){
            q.push(child);
        }
    }
}

int main(){
    Node* root;
    vector<int> eulerPath = {10,20,-1,30,40,100,-1,-1,50,-1,-1,60,-1,-1};
    createTree(root,eulerPath);
    traversal(root);   
    
}