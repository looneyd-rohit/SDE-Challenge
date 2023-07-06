// Leetcode 1047

class Solution {
public:
    string removeDuplicates(string s) {
        int n = s.length();
        stack<char> st;
        for(int i=0; i<n; i++){
            char ch = s[i];
            if(st.empty()){
                st.push(ch);
            }else{
                if(st.top()==ch) st.pop();
                else st.push(ch);
            }
        }
        string ans = "";
        while(!st.empty()) ans.push_back(st.top()), st.pop();
        reverse(begin(ans), end(ans));
        return ans;
    }
};