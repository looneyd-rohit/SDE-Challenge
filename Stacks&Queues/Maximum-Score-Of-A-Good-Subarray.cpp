// Leetcode 1793

class Solution {
public:
    void computeNSME(vector<int>& nums, vector<int>& ans){
        int n = nums.size();
        stack<int> st;
        st.push(n);
        for(int i=n-1; i>=0; i--){
            while(st.top()!=n && nums[st.top()]>=nums[i]){
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }
    }
    void computePSME(vector<int>& nums, vector<int>& ans){
        int n = nums.size();
        stack<int> st;
        st.push(-1);
        for(int i=0; i<n; i++){
            while(st.top()!=-1 && nums[st.top()]>=nums[i]){
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }
    }
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> psme(n), nsme(n);
        computePSME(nums, psme);
        computeNSME(nums, nsme);
        int maxi = 0;
        for(int i=0; i<n; i++){
            int prev = psme[i], next = nsme[i];
            if(prev+1<=k && k<=next-1){
                int diff = next-prev-1;
                maxi = max(maxi, nums[i]*diff);
            }
        }
        return maxi;
    }
};