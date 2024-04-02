// Leetcode 1673

// Approach: monotonic stack + greedy
class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        int n = nums.size();
        stack<int> st;
        for(int i=0; i<n; i++){
            while(!st.empty() && st.top()>nums[i] && st.size()+(n-i)>k) st.pop();
            if(st.size()<k) st.push(nums[i]);
        }
        vector<int> ans;
        while(!st.empty()) ans.push_back(st.top()), st.pop();
        reverse(begin(ans), end(ans));
        return ans;
    }
};