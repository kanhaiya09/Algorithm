//  https://leetcode.com/problems/minimum-genetic-mutation/description/

#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;


int minMutation(string start, string end, vector<string>& bank) {
    unordered_set<string> st(bank.begin(),bank.end());
    char alpha[4] = {'A','C','G','T'};
    queue< pair<string,int> >q;
    q.push({start,0});
    st.erase(start);

    while(!q.empty()){
        auto [word,steps] = q.front();
        q.pop();

        if(word==end)
            return steps;
        
        for(int i = 0 ; i < word.size() ; i++){
            char orig = word[i];
            for(char ch : alpha){
                word[i] = ch;
                if(st.count(word)>0){
                    q.push({word, steps+1});
                    st.erase(word);
                }
            }
            word[i] = orig;
        }
    }
    return -1;
}
