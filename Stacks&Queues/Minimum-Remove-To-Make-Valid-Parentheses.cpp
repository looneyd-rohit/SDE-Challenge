// Leetcode 1249

// Approach: basic stack based approach
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.length();
        stack<int> st;
        for(int i=0; i<n; i++){
            char ch = s[i];
            if(ch!='(' && ch!=')') continue;
            if(st.empty()){
                st.push(i);
            }else{
                if(s[st.top()]=='(' && ch==')') st.pop();
                else st.push(i);
            }
        }
        while(!st.empty()){
            s[st.top()] = '#';
            st.pop();
        }
        string ans = "";
        for(int i=0; i<n; i++){
            if(s[i]=='#') continue;
            ans.push_back(s[i]);
        }
        return ans;
    }
};