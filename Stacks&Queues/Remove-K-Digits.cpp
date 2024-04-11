// Leetcode 402

// Approach: monotonic stack (remove any continuous decreasing sequence)
class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        if(n == k) return "0";
        // remove any continuous decreasing sequence from
        // the string
        stack<int> st;
        for(int i=0; i<n; i++){
            char ch = num[i];
            while(!st.empty() && num[st.top()] > ch && k) st.pop(), k--;
            st.push(i);
        }
        // if any length remains, remove from the last
        string ans = "";
        while(!st.empty()){
            ans.push_back(num[st.top()]);
            st.pop();
        }
        reverse(begin(ans), end(ans));
        if(k) ans = ans.substr(0, ans.size()-k);
        // remove leading zeros
        int ind = 0;
        for(; ind<ans.size(); ind++) if(ans[ind] > '0') break;
        ans = ans.substr(ind);
        if(ans == "") return "0";
        return ans;
    }
};