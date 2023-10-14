// Leetcode 2104

class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        st.push(-1);
        long long ans = 0;
        // to get the largest, maintain a non increasing sequence
        nums.push_back(INT_MAX);
        for(int i=0; i<=n; i++){
            while(st.top()!=-1 && nums[st.top()] < nums[i]){
                int ind = st.top(); st.pop();
                int prev = st.top();
                ans += 1LL * nums[ind] * (i-ind) * (ind-prev);
            }
            st.push(i);
        }
        nums.pop_back();
        stack<int> st2;
        st2.push(-1);
        // to get the smallest, maintain a non decreasing sequence
        nums.push_back(INT_MIN);
        for(int i=0; i<=n; i++){
            while(st2.top()!=-1 && nums[st2.top()] > nums[i]){
                int ind = st2.top(); st2.pop();
                int prev = st2.top();
                ans -= 1LL * nums[ind] * (i-ind) * (ind-prev);
            }
            st2.push(i);
        }
        nums.pop_back();
        return ans;
    }
};