// Leetcode 2602

class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        int n = nums.size(), m = queries.size();
        sort(begin(nums), end(nums));
        vector<long long> prefix(n, nums[0]);
        for(int i=1; i<n; i++) prefix[i] = prefix[i-1] + 1LL*nums[i];
        vector<long long> ans(m, 0);
        for(int i=0; i<m; i++){
            int q = queries[i];
            int ind = upper_bound(begin(nums), end(nums), q) - begin(nums);
            long long smaller = ((ind > 0) ? prefix[ind-1] : 0);
            long long smallerReq = ind * 1LL * q;
            long long greater = prefix[n-1] - ((ind > 0) ? prefix[ind-1] : 0);
            long long greaterReq = (n - ind) * 1LL * q;
            long long count = (smallerReq - smaller) + (greater - greaterReq);
            ans[i] = count;
        }
        return ans;
    }
};