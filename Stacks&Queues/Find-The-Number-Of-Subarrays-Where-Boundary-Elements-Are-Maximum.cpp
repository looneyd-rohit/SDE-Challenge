// Leetcode 3113

// Approach: stack with next greater element logic
class Solution {
public:
    vector<int> computeNGE(vector<int>& nums){
        int n = nums.size();
        stack<int> st;
        st.push(n);
        vector<int> ans(n, n);
        for(int i=n-1; i>=0; i--){
            while(st.top()!=n && nums[st.top()] <= nums[i]) st.pop();
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
    long long numberOfSubarrays(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> usst;
        for(int i=0; i<n; i++){
            usst[nums[i]].push_back(i);
        }
        vector<int> nge = computeNGE(nums);
        long long ans = 0;
        for(int i=0; i<n; i++){
            int l = i;
            int r = nge[i] - 1;
            // find count of nums[i] between l and r-1
            int x = lower_bound(begin(usst[nums[i]]), end(usst[nums[i]]), l) - begin(usst[nums[i]]);
            int y = upper_bound(begin(usst[nums[i]]), end(usst[nums[i]]), r) - begin(usst[nums[i]]);
            ans += abs(y - x);
        }
        return ans;
    }
};