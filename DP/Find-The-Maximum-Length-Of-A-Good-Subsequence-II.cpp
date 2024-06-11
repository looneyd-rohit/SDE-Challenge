// Leetcode 3177

// Approach: optimization of LIS based approach to reduce one nested for loop
class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();
        // LIS pattern --> use bottom up approach
        // dp[i][k] --> maximum length of subsequence ending at index i
        // with exactly k non equal adjacent pairs
        // transtions:
        // dp[i][k] = 1 + max(dp[j][k]) where nums[i] == nums[j]
        // dp[i][k] = 1 + max(dp[j][k-1]) where nums[i] != nums[j]
        vector<unordered_map<int, int>> dp(k+1);
        vector<int> max_overall_dp(k+1, 0);
        int maxi = 1;
        for(int i=0; i<n; i++){
            for(int len=k; len>=0; len--){
                
                // equal
                dp[len][nums[i]] = max(dp[len][nums[i]], 1 + dp[len][nums[i]]);

                // not equal
                if(len > 0) dp[len][nums[i]] = max(dp[len][nums[i]], 1 + max_overall_dp[len-1]);

                max_overall_dp[len] = max(max_overall_dp[len], dp[len][nums[i]]);

                maxi = max(maxi, dp[len][nums[i]]);
            }
        }
        return maxi;
    }
};