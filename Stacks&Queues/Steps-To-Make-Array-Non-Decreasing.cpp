// Leetcode 2289
// [IMP]: stack + DP
class Solution {
public:
    int totalSteps(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        vector<int> dp(n, 0);
        int ans = 0;
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && nums[st.top()]<nums[i]){
                dp[i]++;
                dp[i] = max(dp[i], dp[st.top()]);
                st.pop();
            }
            ans = max(ans, dp[i]);
            st.push(i);
        }
        return ans;
    }
};