// Leetcode 150

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        stack<string> st;
        for(int i=0; i<n; i++){
            string token = tokens[i];
            if(token == "+" || token == "-" || token == "*" || token == "/"){
                string num2_ = st.top(); st.pop();
                int num2 = stoi(num2_);
                string num1_ = st.top(); st.pop();
                int num1 = stoi(num1_);
                int res = 0;
                if(token == "+"){
                    res = num1 + num2;
                }else if(token == "-"){
                    res = num1 - num2;
                }else if(token == "*"){
                    res = num1 * num2;
                }else{
                    res = num1 / num2;
                }
                st.push(to_string(res));
            }else{
                st.push(token);
            }
        }
        return stoi(st.top());
    }
};