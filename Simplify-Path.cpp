// Leetcode 71

class Solution {
public:
    string simplifyPath(string path) {
        path.push_back('/');
        int n = path.length();
        stack<char> st;
        // cout<<path<<endl;
        for(int i=0; i<n; i++){
            char ch = path[i];
            if(ch == '/'){
                if(st.empty()){
                    st.push(ch);
                }else{
                    char top = st.top();
                    if(top == '/') continue;
                    else if(top == '.'){
                        // check for double dots
                        if(st.size() > 2){
                            st.pop();
                            int top2 = st.top(); st.pop();
                            if(top2 == '.'){
                                char top3 = st.top(); st.pop();
                                if(top3 == '/'){
                                    while(!st.empty() && st.top()!='/') st.pop();
                                    // st.push(ch);
                                }else{
                                    st.push(top3); st.push(top2); st.push(top);
                                    st.push(ch);
                                }
                            }else if(top2 == '/'){
                                // cout<<"hi"<<endl;
                                st.push(top2);
                                continue;
                            }else{
                                st.push(top2); st.push(top); st.push(ch);
                            }
                        }else{
                            st.pop();
                            if(st.top()=='/') continue;
                        }
                    }else{
                        st.push('/');
                    }
                }
            }else{
                st.push(ch);
            }

            if(st.empty()) st.push('/');
        }
        string ans = "";
        while(!st.empty()){
            ans.push_back(st.top()); st.pop();
        }
        reverse(begin(ans), end(ans));
        if(ans.back()=='/' && ans.length() > 1) ans.pop_back();
        return ans;
    }
};