// Leetcode 921

class Solution {
public:
    int minAddToMakeValid(string s) {
        // calculate minimum steps required to match one '(' with ')'
        int n = s.length();
        stack<char> st;
        for(int i=0; i<n; i++){
            char ch = s[i];
            if(ch == '('){
                st.push(ch);
            }else{
                if(!st.empty()){
                    if(st.top() == '(') st.pop();
                    else st.push(ch);
                }else{
                    st.push(ch);
                }
            }
        }
        return st.size();
    }
};