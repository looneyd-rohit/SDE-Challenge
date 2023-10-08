// Leetcode 343

class Solution {
public:
    int dp[69];
    int solve(int num){
        // base case
        if(num == 1) return 1;

        // dp check
        if(dp[num]!=-1) return dp[num];

        int ans = 0;
        for(int l=1; l<=num; l++){
            ans = max({ans, l * solve(num-l), l*(num-l)});
        }
        return dp[num] = ans;
    }
    int integerBreak(int n) {
        memset(dp, -1, sizeof(dp));
        return solve(n);
    }
};