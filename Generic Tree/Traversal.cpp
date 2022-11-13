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
*/    



void traversal(Node* root){
    int data = root->data;
    cout<<"Node Pre : " <<data<<"\n";
    for(int i = 0 ; i < root->children.size() ; i++)
    {
        int childData = root->children[i]->data;
        cout<<"Edge Pre : " << data << " -- " <<childData<<"\n";
        traversal(root->children[i]);   
        cout<<"Edge Post : " << data << " -- " <<childData<<"\n";
    }
     cout<<"Node Post : " <<data<<"\n";
}

int main(){
    Node* root;
    vector<int> eulerPath = {10,20,-1,30,40,100,-1,-1,50,-1,-1,60,-1,-1};
    createTree(root,eulerPath);
    traversal(root);   
    
}