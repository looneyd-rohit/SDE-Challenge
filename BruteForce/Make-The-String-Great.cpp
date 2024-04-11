// Leetcode 1544

class Solution {
public:
    bool check(char a, char b){
        return ((char)tolower(a)==(char)tolower(b)) && ((a-'a'>=0 && a-'a'<=25 && b-'A'>=0 && b-'A'<=25) || (b-'a'>=0 && b-'a'<=25 && a-'A'>=0 && a-'A'<=25));
    }
    string makeGood(string s) {
        int n = s.length();
        stack<char> st;
        for(int i=0; i<n; i++){
            char ch = s[i];
            if(st.empty()) st.push(ch);
            else{
                if(check(st.top(), ch)) st.pop();
                else st.push(ch);
            }
        }
        string ans = "";
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(begin(ans), end(ans));
        return ans;
    }
};