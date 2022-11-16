// https://leetcode.com/problems/implement-trie-prefix-tree/

#include<bits/stdc++.h>
using namespace std;


class TrieNode{
public:
    char data;
    TrieNode* children[26];
    bool isTerminal;
    int childCnt;

    TrieNode(char ch){
        data = ch;
        for(int i = 0 ; i < 26 ; i++){
            children[i] = NULL;
        }
        isTerminal = false;
        childCnt = 0;
    }

};

class Trie{
public:

    TrieNode *root;

    Trie(){
        root = new TrieNode('\0');
    }

public:
    void insert(string word){
        insertUtil(root,word);
    }

    bool search(string word){
        return searchUtil(root,word);
    }

    bool startsWith(string prefix){
        return startsWithUtil(root,prefix);
    }

    string longestCommonPrefix(string word){
        string ans = "";
        TrieNode * curr = root;
        for(int i = 0 ; i < word.length() ; i++){
            char ch = word[i];
            int idx = ch-'a';
            if(curr->children[idx]==NULL){
                break;
            }else{

            }
        }
        return ans;
    }

    vector<string> getSuggestion(TrieNode* root){
        vector<string> ans;
        cout<<root->childCnt<<"\n";
        suggestionHelper(root,ans,"");
        return ans;
    }

private:
    void insertUtil(TrieNode * root, string word){
        if(word.length()==0){
            root->isTerminal = true;
            return;
        }else{
            char ch = word[0];
            string rest =  word.substr(1);
            int index = ch-'a';
            if(root->children[index]==NULL){
                root->children[index] = new TrieNode(ch);
                root->childCnt++;
                insertUtil(root->children[index],rest);
            }else{
                insertUtil(root->children[index],rest);
            }
        }
    }

    bool searchUtil(TrieNode* root,string word){
        if(word.length()==0){
            return root->isTerminal;
        }
        char ch = word[0];
        string rest = word.substr(1);
        int idx = ch-'a';

        if(root->children[idx]==NULL)
            return false;
        else{
            return searchUtil(root->children[idx],rest);
        }
    }

    
    bool startsWithUtil(TrieNode* root,string word){
        if(word.length()==0){
            return true;
        }
        char ch = word[0];
        string rest = word.substr(1);
        int idx = ch-'a';

        if(root->children[idx]==NULL)
            return false;
        else
            return startsWithUtil(root->children[idx],rest);
    }


    void suggestionHelper(TrieNode* root, vector<string>& out,string prefix){    
        if(root->isTerminal)
        {
            out.push_back(prefix);
        }else{
            for(int i = 0 ; i < 26 ; i++ ){
                if(root->children[i] != NULL){
                    char ch = root->children[i]->data;
                    suggestionHelper(root->children[i],out,prefix+string(1,ch));
                }
            }    
        }
    }

};


int main(){
    Trie *t = new Trie();
    t->insert("abcd");   
    t->insert("arm");
    t->insert("abs");
    t->insert("do");
    t->insert("time");
    cout<<t->root->childCnt<<"\n";
    // cout<<boolalpha<<t->search("abcd")<<"\n";
    // cout<<boolalpha<<t->search("bcd")<<"\n";
    // cout<<boolalpha<<t->search("abc")<<"\n";
    cout<<boolalpha<<t->search("arm")<<"\n";
    // cout<<boolalpha<<t->search("tim")<<"\n";
    // cout<<boolalpha<<t->search("do")<<"\n";

    vector<string> trie = t->getSuggestion(t->root);
    cout<<"{ ";
    for(string tmp : trie){
        cout<<tmp<<" , ";
    }
    cout<<" }";
}