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
           /        |        \
        20          30       40
      /    \      /  |  \       \ 
    50      60  70   80  90    100
                    /  \
                   110 120
    input data  : {10,20,50,-1,60,-1,-1,30,70,-1,80,110,
                  -1,120,-1,-1,90,-1,-1,40,100,-1,-1,-1};

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
    20 30 40 
    50 60 70 80 90 100 
    110 120 
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
/*
    Print in spiral order
    10
    40 30 20
    50 60 70 80 90 100
    110 120
*/

void printSpiral(Node* root){
    stack<Node*> ms;
    stack<Node*> cs;
    ms.push(root);
    int level = 1;
    while(!ms.empty()){
        Node* tmp = ms.top();
        ms.pop();
        cout<<tmp->data<<" ";
        if(level%2==0){   //add child from left to right in cs stack
            for(int i = tmp->children.size()-1 ; i >=0 ;i--){
                cs.push(tmp->children[i]);
            }
        }else{           // add child from right to left
            for(int i = 0 ; i < tmp->children.size() ;i++){
                cs.push(tmp->children[i]);
            }
        }
        
        if(ms.empty()){
            level++;
            cout<<"\n";
            swap(ms,cs);
        }
    }
}


void printSpiral2(Node* root){
    stack<Node*> s1;
    stack<Node*> s2;
    s1.push(root);
    
    while(!s1.empty() or !s2.empty()){
        while(!s1.empty()){
            Node* tmp = s1.top();
            s1.pop();
            cout<<tmp->data<<" ";
            for(int i = 0 ; i < tmp->children.size() ;i++){
                s2.push(tmp->children[i]);
            }
        }
        cout<<"\n";
        while(!s2.empty()){
            Node* tmp = s2.top();
            s2.pop();
            cout<<tmp->data<<" ";
            for(int i = tmp->children.size()-1 ; i >=0 ;i--){
                s1.push(tmp->children[i]);
            }
        }
        cout<<"\n";
    }
}



int main(){
    Node* root;
    vector<int> eulerPath = {10,20,50,-1,60,-1,-1,30,70,-1,80,110,
                            -1,120,-1,-1,90,-1,-1,40,100,-1,-1,-1};
    createTree(root,eulerPath);
    printLevelInNewLine(root);
    printSpiral(root);
    printSpiral2(root);
}