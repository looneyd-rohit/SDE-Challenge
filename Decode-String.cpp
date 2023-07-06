// Leetcode 394

class Solution {
public:
    string decodeString(string s) {
        int n = s.length();
        stack<char> st;
        for(int i=0; i<n; i++){
            char ch = s[i];
            if(ch != ']'){
                st.push(ch);
            }else{
                // make the encoding the current bracket sequence [...]
                string temp = "";
                while(!st.empty() && st.top()!='['){
                    temp.push_back(st.top()); st.pop();
                }
                reverse(begin(temp), end(temp));
                // pop the front bracket
                st.pop();
                // pop the integer 
                string str_num = "";
                while(!st.empty() && st.top()>='0' && st.top()<='9'){
                    str_num.push_back(st.top()); st.pop();
                }
                reverse(begin(str_num), end(str_num));
                int num = stoi(str_num);
                // now take this sequence and add it back to stack
                for(int i=0; i<num; i++){
                    for(auto& e: temp){
                        st.push(e);
                    }
                }
            }
        }
        string ans = "";
        while(!st.empty()){
            char ch = st.top(); st.pop();
            ans.push_back(ch);
        }
        reverse(begin(ans), end(ans));
        return ans;
    }
};