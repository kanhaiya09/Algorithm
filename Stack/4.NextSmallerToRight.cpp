//https://practice.geeksforgeeks.org/problems/help-classmates--141631/1?

vector<int> help_classmate(vector<int> arr, int n) 
{ 
    // Your code goes here
    stack<int> st;
    vector<int> ans(n,-1);
    
    for(int i = 0 ; i < n ; i++){
        while(!st.empty() and arr[st.top()]> arr[i]){
            ans[st.top()] = arr[i];
            st.pop();
        }
        st.push(i);
    }
    return ans;
} 
