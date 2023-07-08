// Leetcode 735

class Solution {
public:
    bool isColliding(vector<int>& asteroids, int i, int j){
        return asteroids[i] > 0 && asteroids[j] < 0;
    }
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        stack<int> st;
        st.push(0);
        for(int i=1; i<n; i++){
            bool isInsert = true;
            while(!st.empty() && isColliding(asteroids, st.top(), i)){
                int leftHealth = abs(asteroids[st.top()]);
                int rightHealth = abs(asteroids[i]);
                if(leftHealth < rightHealth){
                    st.pop();
                }else if(leftHealth > rightHealth){
                    isInsert = false;
                    break;
                }else{
                    st.pop();
                    isInsert = false;
                    break;
                }
            }
            if(isInsert) st.push(i);
        }
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(asteroids[st.top()]); st.pop();
        }
        reverse(begin(ans), end(ans));
        return ans;
    }
};