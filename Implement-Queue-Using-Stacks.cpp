// Leetcode 232

// Approach 1:
// TC: O(N), SC: O(2*N)
class MyQueue {
public:
    stack<int> st1;
    stack<int> st2;
    MyQueue() {
        
    }
    
    void push(int x) {
        // move st1 to st2
        while(!st1.empty()){
            st2.push(st1.top());
            st1.pop();
        }
        // push current element
        st1.push(x);
        // st2 to st1
        while(!st2.empty()){
            st1.push(st2.top());
            st2.pop();
        }
    }
    
    int pop() {
        int top = st1.top(); st1.pop();
        return top;
    }
    
    int peek() {
        return st1.top();
    }
    
    bool empty() {
        return st1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */


// Approach 2:
// TC: O(1) for pushing and O(1) for popping -> (armortized) SC: O(2*N)
class MyQueue {
public:
    stack<int> st1;
    stack<int> st2;
    MyQueue() {
        
    }
    
    void push(int x) {
        // while pushing try to keep it O(1)
        st1.push(x);
    }
    
    int pop() {
        if(!st2.empty()){
            int top = st2.top(); st2.pop();
            return top;
        }else{
            while(!st1.empty()){
                st2.push(st1.top()); st1.pop();
            }
            int top = st2.top(); st2.pop();
            return top;
        }
    }
    
    int peek() {
        if(!st2.empty()){
            int top = st2.top();
            return top;
        }else{
            while(!st1.empty()){
                st2.push(st1.top()); st1.pop();
            }
            int top = st2.top();
            return top;
        }
    }
    
    bool empty() {
        return st1.empty() && st2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */