// Leetcode 503

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        // finding the next greater element for 2*n-1 size of the array
        int n = nums.size();
        stack<int> st;
        vector<int> nge(n, -1);
        for(int i=2*n-2; i>=0; i--){
            int e = (i >= n) ? nums[i-n] : nums[i];
            while(!st.empty() && st.top() <= e) st.pop();
            if(!st.empty() && i<n) nge[i] = st.top();
            st.push(e);
        }
        return nge;
    }
};