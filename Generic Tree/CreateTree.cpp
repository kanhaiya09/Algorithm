#include <bits/stdc++.h>
using namespace std;


struct Node{
    int data;
    vector<Node *> children;

    Node(int n){
        data = n;
    }   
};

/*
*  createTree from euler path , if Node is leaf it's child is -1 
*  e.g.
             10
           /  |  \
        20   30   60
            /  \
           40  50
    
    input data  : 10 20 -1 30 40 -1 50 -1 -1 60 -1 -1

1.create a stack
2.iterate through the data 
3.if data is -1 pop from stack
4.else
    4.1 create a node from data
    4.2 if stack is empty that newly create node is root
    4.3 else add the newly create node to the children of top of stack 

*/


void createTree(Node* &root,vector<int>& data){
    stack<Node* > st;  
    for(int i = 0 ; i < data.size() ; i++){
        if(data[i]==-1)
            st.pop();
        else{
            Node * child = new Node(data[i]);
            if(st.empty()){
                root = child;
            }else{
                st.top()->children.push_back(child);
            }
            st.push(child);
        }
    }
}


void displayTree(Node* root){
    if(root->children.size()==0){
        cout<<root->data << " -> " <<".\n";
    }else{
        cout<<root->data <<" -> ";
        for(int i = 0 ; i < root->children.size() ; i++){
            int data = root->children[i]->data;
            cout<<data << " , ";
        }
        cout<<"\n";

        for(int i = 0 ; i < root->children.size() ; i++){
            displayTree(root->children[i]);
        }
    }
}


void displayTree2(Node* root){
    cout<<root->data <<" -> ";
    for(int i = 0 ; i < root->children.size() ; i++){
        cout<<root->children[i]->data <<" , ";
    }
    cout<<".\n";

    for(int i = 0 ; i < root->children.size() ; i++){
        displayTree2(root->children[i]);
    }
}

int main(){
    Node* root;
    vector<int> eulerPath = {10,20,-1,30,40,-1,50,-1,-1,60,-1,-1};
    createTree(root,eulerPath);
    displayTree(root);
    displayTree2(root);

}


