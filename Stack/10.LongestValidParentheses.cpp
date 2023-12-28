// https://leetcode.com/problems/longest-valid-parentheses/description/

//  string s: ( ( ) ) ) ( ( ( ) ( ) ) )  
//  is_ok   : T T T T F T T T T T T T T
//  find the longest consecutive T 

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.size();
        vector<bool> is_ok(n,false);
        stack<int> st;
        for(int i = 0 ; i < n ; i++)
        {
            if(s[i]=='(')
                st.push(i);
            else if(s[i]==')'){
                if(!st.empty()){
                    is_ok[st.top()] = true;
                    is_ok[i] = true;
                    st.pop();
                }
            }else  // other alphabets are ok
                is_ok[i] = true;
        }
        
        string res= "";
        for(int i =0  ; i < n ; i++){
            if(is_ok[i])
                res+= s[i];
        }
        
        return res;
    }
};

