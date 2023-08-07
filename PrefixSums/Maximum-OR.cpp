// Leetcode 2680

class Solution {
public:
    long long maximumOr(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefixOR(n, nums.front()), suffixOR(n, nums.back());
        for(int i=1; i<n; i++){
            prefixOR[i] = prefixOR[i-1] | nums[i];
            suffixOR[n-1-i] = suffixOR[n-i] | nums[n-1-i];
        }
        long long ans = 0;
        for(int i=0; i<n; i++){
            ans = max(ans, ((i>0)?prefixOR[i-1]:0) | ((nums[i]*1LL)<<k) | ((i<n-1)?suffixOR[i+1]:0));
        }
        return ans;
    }
};