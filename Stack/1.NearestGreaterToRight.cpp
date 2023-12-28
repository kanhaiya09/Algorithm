//https://www.geeksforgeeks.org/problems/next-larger-element-1587115620/1?

 public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n){
      
        vector<long long> ans(n, -1);
        stack<int > st;
        // Method 1 : traversing from the right 
        // for(int i = n-1; i>= 0 ; i--){
        //     while(!st.empty() and st.top()<=arr[i]){
        //         st.pop();
        //     }
        //     ans[i] = st.empty() ? -1: st.top();
        //     st.push(arr[i]);
        // }

        // Method 2 : traversing from the left
        for(int i = 0 ; i < n ; i++){
            while(!st.empty() and arr[st.top()] < arr[i]){
                ans[st.top()] = arr[i];
                st.pop();
            }      
            st.push(i);
        }
      
        return ans;
    }
