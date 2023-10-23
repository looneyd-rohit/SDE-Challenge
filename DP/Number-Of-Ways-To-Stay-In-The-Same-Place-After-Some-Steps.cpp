// Leetcode 1269

class Solution {
public:
    const int M = 1e9+7;
    long long dp[501][501];
    long long solve(int index, int steps, int n){
        // base case
        if(steps == 0) return (index==0);
        if(index < 0 || index >= n) return 0;

        // dp check
        if(dp[index][steps]!=-1) return dp[index][steps];

        return dp[index][steps] = ((solve(index+1, steps-1, n) % M) + (solve(index, steps-1, n) % M) + (solve(index-1, steps-1, n) % M) % M);
    }
    int numWays(int steps, int arrLen) {
        // dp[index][steps] --> max no. of ways in which we can have a
        // round trip starting from 0-th index and ending at 0-th index
        // with steps no. of steps
        memset(dp, -1, sizeof(dp));
        return ((solve(0, steps, arrLen) % M) + M) % M;
    }
};