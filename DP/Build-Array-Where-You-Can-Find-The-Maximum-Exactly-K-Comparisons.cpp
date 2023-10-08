// Leetcode 1420

class Solution {
public:
    const int M = 1e9+7;
    int dp[51][51][102];
    int solve(int index, int cost, int maxi, int n, int m, int k){
        // base case
        if(index >= n){
            return (cost == k);
        }
        // dp check
        if(dp[index][cost][maxi+1]!=-1) return dp[index][cost][maxi+1];

        int ans = 0;
        for(int val=1; val<=m; val++){
            ans += solve(index+1, cost + (val>maxi), max(maxi, val), n, m, k) % M;
            ans %= M;
        }
        return dp[index][cost][maxi+1] = ans % M;
    }
    int numOfArrays(int n, int m, int k) {
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, -1, n, m, k);
    }
};