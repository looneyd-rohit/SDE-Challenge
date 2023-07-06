// Leetcode 1003

class Solution {
public:
    bool isValid(string s) {
        int n = s.length();
        stack<char> st;
        for(int i=0; i<n; i++){
            char ch = s[i];
            if(st.empty()){
                st.push(ch);
            }else{
                if(ch == 'c'){
                    char top1 = st.top(); st.pop();
                    if(!st.empty()){
                        char top2 = st.top(); st.pop();
                        if(top2 == 'a' && top1 == 'b') continue;
                        st.push(top2); st.push(top1); st.push(ch);
                    }else{
                        st.push(top1);
                    }
                }else{
                    st.push(ch);
                }
            }
        }
        if(st.empty()) return true;
        return false;
    }
};