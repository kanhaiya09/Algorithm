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
*  return the height of the tree represented by euler path 
*  e.g.
             10
           /  |  \
        20   30   60
            /  \
           40  50
           /
         100
    output : 3 
*/    



int getHeight(Node* root){
    int height = -1;
    for(int i = 0 ; i < root->children.size() ; i++){
        int childHeight = getHeight(root->children[i]);
        height = max(height,childHeight);
    }
    return height+1;
}

int main(){
    Node* root;
    vector<int> eulerPath = {10,20,-1,30,40,100,-1,-1,50,-1,-1,60,-1,-1};
    createTree(root,eulerPath);
    displayTree(root);
    cout << "Height of the tree is : " << getHeight(root);   
}