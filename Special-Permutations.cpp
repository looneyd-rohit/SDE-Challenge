// Leetcode 2741

class Solution {
public:
    const int M = 1e9+7;
    int solve(int index, int prevIndex, int mask, vector<int>& nums, vector<vector<int>>& dp){
        // base case
        if(index >= nums.size()) return 1;

        // dp check
        if(dp[prevIndex+1][mask]!=-1) return dp[prevIndex+1][mask];

        int ans = 0;
        for(int i=0; i<nums.size(); i++){
            if(mask == 0){
                // no element is selected
                ans = ans + solve(index+1, i, mask | (1<<i), nums, dp);
                ans = ans % M;
            }else{
                // already taken
                if(mask & (1<<i)) continue;

                if((nums[prevIndex] % nums[i] == 0) || (nums[i] % nums[prevIndex] == 0 )){
                    ans = ans + solve(index+1, i, mask | (1<<i), nums, dp);
                    ans = ans % M;
                }
            }
        }
        return dp[prevIndex+1][mask] = ans % M;
    }
    int specialPerm(vector<int>& nums) {
        int n = nums.size();
        // memoization:
        vector<vector<int>> dp(n+1, vector<int>(pow(2, n), -1));
        return solve(0, -1, 0, nums, dp) % M;
    }
};