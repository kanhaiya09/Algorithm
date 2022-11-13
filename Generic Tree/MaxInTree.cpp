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


void displayTree(Node* root){
    cout<<root->data <<" -> ";
    for(int i = 0 ; i < root->children.size() ; i++){
        cout<<root->children[i]->data <<" , ";
    }
    cout<<".\n";

    for(int i = 0 ; i < root->children.size() ; i++){
        displayTree(root->children[i]);
    }
}

/*
*  return the maximum in the tree represented by euler path 
*  e.g.
             10
           /  |  \
        20   30   60
            /  \
           40  50

    output : 60 
*/    



int getMax(Node* root){
    int maximum = root->data ;  // size of current node
    for(int i = 0 ; i < root->children.size() ; i++){
        int childMax = getMax(root->children[i]);
        maximum = max(maximum,childMax);
    }
    return maximum;
}

int main(){
    Node* root;
    vector<int> eulerPath = {10,20,-1,30,40,-1,50,-1,-1,60,-1,-1};
    createTree(root,eulerPath);
    displayTree(root);
    cout << "Maximum in the tree is : <<" << getMax(root);   
}