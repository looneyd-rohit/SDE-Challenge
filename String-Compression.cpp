// Leetcode 443

class Solution {
public:
    int compress(vector<char>& chars) {
        // misleading tags: USE STACK for simplicity
        int n = chars.size();
        stack<pair<char, int>> st;
        for(int i=0; i<n; i++){
            char ch = chars[i];
            if(!st.empty() && st.top().first == ch){
                auto top = st.top(); st.pop();
                st.push({top.first, top.second+1});
            }else{
                st.push({ch, 1});
            }
        }
        string ans = "";
        while(!st.empty()){
            auto top = st.top(); st.pop();
            if(top.second == 1){
                ans.push_back(top.first);
            }else{
                string str_num = to_string(top.second);
                reverse(begin(str_num), end(str_num));
                ans += str_num;
                ans.push_back(top.first);
            }
        }
        reverse(begin(ans), end(ans));
        for(int i=0; i<ans.length(); i++){
            chars[i] = ans[i];
        }
        return ans.length();
    }
};