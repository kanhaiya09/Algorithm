// https://leetcode.com/problems/design-add-and-search-words-data-structure/

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

    bool containsKey(char ch){
        return children[ch-'a'] != NULL;
    }

    void putChild(char ch){
        data = ch;
        children[ch-'a'] = new TrieNode(ch);
        childCnt++;
    }


    TrieNode* getChild(char ch){
        return children[ch-'a'];
    }
};

class WordDictionary {
public:
    WordDictionary() {
        root = new TrieNode('\0');        
    }
    
    void addWord(string word) {
        TrieNode* curr = root;
        for(int i =0 ; i < word.size() ; i++){
            char ch = word[i];
            if(!curr->containsKey(ch)){
                curr->putChild(ch);
            }
            curr = curr->getChild(ch);
        }
        curr->isTerminal = true;
    }
    
    bool search(string word) {
       return searchUtil(root,word);
    }
private:
    TrieNode *root;
    
    bool searchUtil(TrieNode* root, string word){
        for(int i = 0; i < word.size(); i++){
            char ch = word[i];
            if(ch != '.'){
                if(!root->containsKey(ch)) return false;
                root = root->getChild(ch);
            }
            else{
                bool found = false;
                for(int j = 0; j < 26; j++){
                    if(root->children[j]) found |= searchUtil(root->children[j],word.substr(i + 1));
                    if(found) return true;
                }
                return false;
            }
        }
        return root->isTerminal;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */