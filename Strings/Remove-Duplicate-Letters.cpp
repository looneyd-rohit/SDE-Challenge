// Leetcode 316

class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.length();
        stack<int> st;
        vector<int> freq(26, 0), visited(26, 0);
        for(int i=0; i<n; i++) freq[s[i]-'a']++;
        for(int i=0; i<n; i++){
            freq[s[i]-'a']--;
            if(visited[s[i]-'a']) continue;
            // maintain a monotonic increasing stack
            while(!st.empty() && s[st.top()] > s[i] && freq[s[st.top()]-'a']>0){
                // since we are popping, it now we have to take it later 
                // so unmark visited
                visited[s[st.top()]-'a'] = 0;
                st.pop();
            }
            st.push(i);
            visited[s[i]-'a'] = 1;
        }
        string ans = "";
        while(!st.empty()){
            ans.push_back(s[st.top()]); st.pop();
        }
        reverse(begin(ans), end(ans));
        return ans;
    }
};