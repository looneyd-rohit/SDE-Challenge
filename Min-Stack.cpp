// Leetcode 155
// [Note]: If u don't know logic it won't be solvable

class MinStack {
public:
    long long int mini;
    stack<long long> st;
    MinStack() {
        mini = LONG_MAX;
    }
    
    void push(int val) {
        if(st.empty()){
            st.push(val);
            mini = val;
        }else{
            // if val > mini
            if(val > mini) st.push(val);
            else {
                long long int new_val = 2*1LL*val - mini;
                st.push(new_val);
                mini = val;
            }
        }
    }
    
    void pop() {
        if(st.top() > mini) st.pop();
        else{
            mini = 2*(mini) - st.top();
            st.pop();
        }
    }
    
    int top() {
        if(st.top() > mini) return st.top();
        return mini;
    }
    
    int getMin() {
        return mini;
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