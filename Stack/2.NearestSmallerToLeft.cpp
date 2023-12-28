// https://practice.geeksforgeeks.org/problems/smallest-number-on-left3403/1?

vector<int> leftSmaller(int n, int a[]){
   stack<int> st;
   vector<int> ans(n,-1);
   for(int i = 0 ; i < n ; i++){
       while(!st.empty() and st.top()>=a[i])
       {
           st.pop();
       }
       ans[i] = st.empty() ? -1 : st.top();
       st.push(a[i]);
   }
   return ans;
}
