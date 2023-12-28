// https://leetcode.com/problems/longest-valid-parentheses/description/

//  string s: ( ( ) ) ) ( ( ( ) ( ) ) )  
//  is_ok   : T T T T F T T T T T T T T
//  find the longest consecutive T 

class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        vector<int> is_ok(n,0);
        stack<int> st;
        
        for(int i = 0 ; i < n ; i++){
            if(s[i]=='(')
                st.push(i);
            else{
                if(!st.empty())
                {
                    is_ok[st.top()] = 1;
                    is_ok[i] = 1;
                    st.pop();
                }
            }
        }
        int cnt = 0;
        int ans = 0;
        for(int i = 0 ; i < n ; i++)
        {
            if(is_ok[i])
                cnt++;
            else
                cnt = 0;
            ans = max(ans,cnt);
        }
        
        return ans;
    }
};
