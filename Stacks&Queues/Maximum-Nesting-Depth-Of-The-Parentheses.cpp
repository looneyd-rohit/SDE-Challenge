// Leetcode 1614

// Approach: simple stack
class Solution {
public:
    int maxDepth(string s) {
        int n = s.length();
        stack<char> st;
        int maxi = 0;
        for(int i=0; i<n; i++){
            char ch = s[i];
            if(ch=='('){
                st.push(ch);
                maxi = max(maxi, (int)st.size());
            }else if(ch==')' && st.top()=='('){
                st.pop();
            }
        }
        return maxi;
    }
};