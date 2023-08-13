// Leetcode 45

class Solution {
public:
    int dp[(int)1e4+1];
    int solve(int index, int n, vector<int>& nums){
        // base case
        if(index == n-1) return 0;

        // dp check
        if(dp[index]!=-1) return dp[index];

        int ans = 1e9;
        int jump = nums[index];
        for(int j=1; j<=jump; j++){
            if(index + j < n){
                ans = min(ans, 1 + solve(index+j, n, nums));
            }
        }
        return dp[index] = ans;
    }
    int jump(vector<int>& nums) {
        int n = nums.size();
        // memoization:
        memset(dp, -1, sizeof(dp));
        int ans = solve(0, n, nums);
        if(ans >= 1e9) return -1;
        return ans;
    }
};