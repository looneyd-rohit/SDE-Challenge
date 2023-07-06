// Leetcode 20

class Solution {
public:
    bool isValid(string s) {
        int n = s.length();
        stack<char> st;
        for(int i=0; i<n; i++){
            char ch = s[i];
            if(ch == '(' || ch == '{' || ch == '['){
                st.push(ch);
            }else{
                if(!st.empty()){
                    char rev = st.top();
                    if(rev == '(' && ch == ')') st.pop();
                    else if(rev == '{' && ch == '}') st.pop();
                    else if(rev == '[' && ch == ']') st.pop();
                    else return false;
                }else{
                    return false;
                }
            }
        }
        return st.size() == 0;
    }
};