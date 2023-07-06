// https://practice.geeksforgeeks.org/problems/reverse-a-stack/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

class Solution{
public:
    void insertAtBottom(stack<int>& st, int e){
        // base case
        if(st.empty()){
            st.push(e);
            return;
        }
        int t = st.top();
        st.pop();
        insertAtBottom(st, e);
        st.push(t);
    }
    void solve(stack<int>& st){
        // base case
        if(st.empty()) return;
        int top = st.top();
        st.pop();
        solve(st);
        insertAtBottom(st, top);
    }
    void Reverse(stack<int> &St){
        solve(St);
    }
};