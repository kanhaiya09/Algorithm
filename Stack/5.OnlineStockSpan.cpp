//https://leetcode.com/problems/online-stock-span/

class StockSpanner {
public:
    stack<pair<int,int>> st;
    int idx;
    StockSpanner() {
        idx = 0;
    }
    
    int next(int price) {
        idx++;
        int ans = 0;
        while(!st.empty() and st.top().first <= price){
            st.pop();
        }
        
        if(st.empty())
            ans = idx;
        else
            ans =  idx-st.top().second;
        st.push({price,idx});
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
