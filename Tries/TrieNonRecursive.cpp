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

    bool containsKey(char ch){
        return children[ch-'a'] != NULL;
    }

    void putChild(char ch){
        children[ch-'a'] = new TrieNode(ch);
        childCnt++;
    }


    TrieNode* getchild(char ch){
        return children[ch-'a'];
    }
};

class Trie{
public:
    Trie(){
        root = new TrieNode('\0');
    }

public:
    void insert(string word){
        TrieNode* curr = root;
        for(int i = 0 ; i < word.size() ; i++){
            char ch = word[i];
            if(!curr->containsKey(ch)){
                curr->putChild(ch);
            }
            curr = curr->getchild(ch);
        }
        curr->isTerminal = true;
    }

    bool search(string word){
        TrieNode* curr = root;
        for(int i = 0 ; i < word.size() ; i++){
            char ch = word[i];
            if(!curr->containsKey(ch)){
                return false;
            }
            curr = curr->getchild(ch);
        }
        return curr->isTerminal;
    }

    bool startsWith(string prefix){
        TrieNode* curr = root;
        for(int i = 0 ; i < prefix.size() ; i++){
            char ch = prefix[i];
            if(!curr->containsKey(ch)){
                return false;
            }
            curr = curr->getchild(ch);
        }
        return true;
    }

private:
    TrieNode *root;
};
