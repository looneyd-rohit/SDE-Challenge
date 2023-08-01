// Leetcode 2696

class Solution {
public:
    int minLength(string s) {
        int n = s.length();
        vector<char> st;
        for(int i=0; i<n; i++){
            char ch = s[i];
            if(st.empty()){
                st.push_back(ch);
            }else{
                if(st.back()=='A' && ch=='B') st.pop_back();
                else if(st.back()=='C' && ch=='D') st.pop_back();
                else st.push_back(ch);
            }
        }
        return st.size();
    }
};