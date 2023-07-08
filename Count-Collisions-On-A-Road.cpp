// Leetcode 2211

class Solution {
public:
    int countCollisions(string directions) {
        int n = directions.size();
        stack<int> st;
        st.push(0);
        int cnt = 0;
        for(int i=1; i<n; i++){
            if(!st.empty() && directions[st.top()]=='R' && directions[i]=='L'){
                auto top = st.top(); st.pop();
                directions[top] = directions[i] = 'S';
                i = top-1;
                cnt += 2;
            }else if(!st.empty() && directions[st.top()]=='R' && directions[i]=='S'){
                auto top = st.top(); st.pop();
                directions[top] = 'S';
                i = top-1;
                cnt += 1;
            }else if(!st.empty() && directions[st.top()]=='S' && directions[i]=='L'){
                directions[i] = 'S';
                st.push(i);
                cnt += 1;
            }else{
                st.push(i);
            }
            // cout<<cnt<<endl;
        }
        return cnt;
    }
};