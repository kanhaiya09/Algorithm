// https://leetcode.com/problems/min-stack/


class MinStack {
public:
    stack<long> st;
    long min;
    MinStack() {
        min = INT_MAX;
    }
    
    void push(int val) {
        if(st.empty()){
            st.push(val);
            min = val;
        }else{
            if(val>min){
                st.push(val);
            }else{
                long flg = 2l * val - min;
                st.push(flg);
                min = val;
            }
        }
    }
    
    void pop() {
        if(st.top() < min){
            long prev = 2l * min - st.top();
            min = prev;
        }
        st.pop();
    }
    
    int top() {
        if(st.top()>min)
            return st.top();
        else
           return min;
    }
    
    int getMin() {
        return min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
