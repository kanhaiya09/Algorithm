#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    vector<Node*> children;

    Node(int n){
        data  = n;
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

void createTree(Node* &root, vector<int>&path){
    stack<Node*> st;
    for(int i = 0 ; i < path.size() ; i++){
        if(path[i]==-1){
            st.pop();
        }else{
            Node *child = new Node(path[i]);
            if(st.empty())
                root = child;
            else{
                st.top()->children.push_back(child);
            }
            st.push(child);
        }
    }
}



/*
    prints tree level by level in new line
    10
    20 30 60
    40 50
*/
void printLevelInNewLine(Node* root){
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        int len = q.size();
        while(len--){
            Node* tmp = q.front();
            q.pop();
            cout<<tmp->data<<" ";
            for(int i = 0 ; i < tmp->children.size() ; i++){
                q.push(tmp->children[i]);
            }
        }
        cout<<"\n";
    }
}


void printLevelInNewLine2(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node * tmp = q.front();
        q.pop();
        if(tmp != NULL){
            cout<<tmp->data<<" ";
            for(int  i = 0 ; i < tmp->children.size() ; i++){
                q.push(tmp->children[i]);
            }
        }else{
            if(q.size()>0){  // when the size of q is greater than 0 then add separator otherwise it will go in infinite loop 
                q.push(NULL);
                cout<<"\n";
            }
        }
    }
    cout<<"\n";
}
/*
level = 1
q  = {10,1}
10
q = {{20,2} , {30,2} , {60,2}}
tmp.second > level
level = 2 and added new line
20 30
q = {{60,2} , {40,3} , {50,3}}
20 30 60
q = { {40,3}, {50,3} }
tmp.second > level
level = 3 and added new line
40 50

*/

void printLevelInNewLine3(Node* root){
    queue<pair<Node*,int>> q;
    int level = 1;
    q.push({root,level});
    
    while(!q.empty()){
        pair<Node*,int> tmp = q.front();
        q.pop();
        if(tmp.second >level){
            level = tmp.second;
            cout<<"\n";
        }
        cout<<tmp.first->data<<" ";
        for(int  i = 0 ; i < tmp.first->children.size() ; i++){
            q.push({tmp.first->children[i],level+1});
        }
    }
}


int main(){
    Node* root;
    vector<int> eulerPath = {10,20,-1,30,40,-1,50,-1,-1,60,-1,-1};
    createTree(root,eulerPath);
    printLevelInNewLine(root);
    printLevelInNewLine2(root);
    printLevelInNewLine3(root);
}