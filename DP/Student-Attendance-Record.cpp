// Leetcode 552

// Approach: normal recursion + memoization
class Solution {
public:
    const int M = 1e9+7;
    long long dp[(int)1e5+1][2][3];
    long long solve(int n, int ab, int lt){
        if(ab == 2 || lt == 3) return 0;
        if(n == 0) return 1;

        if(dp[n][ab][lt]!=-1) return dp[n][ab][lt];


        long long ans = 0;

        // present
        ans += solve(n-1, ab, 0) % M;
        ans %= M;

        // absent
        ans += solve(n-1, ab+1, 0) % M;
        ans %= M;

        // late
        ans += solve(n-1, ab, lt+1) % M;
        ans %= M;

        return dp[n][ab][lt] = ans;
    }
    int checkRecord(int n) {
        memset(dp, -1, sizeof(dp));
        return solve(n, 0, 0) % M;
    }
};