// Leetcode 576

// Approach: top down dp + memoization
class Solution {
public:
    const int M = 1e9+7;
    long long dp[50][50][50];
    long long solve(int i, int j, int move, int maxMove, int m, int n){
        if(i<0 || j<0 || i>=m || j>=n) return 1;

        if(move == maxMove) return 0;

        if(dp[i][j][move]!=-1) return dp[i][j][move];

        long long left = solve(i, j-1, move+1, maxMove, m, n) % M;
        long long right = solve(i, j+1, move+1, maxMove, m, n) % M;
        long long up = solve(i-1, j, move+1, maxMove, m, n) % M;
        long long down = solve(i+1, j, move+1, maxMove, m, n) % M;

        return dp[i][j][move] = (left + right + up + down) % M;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(dp, -1, sizeof(dp));
        return solve(startRow, startColumn, 0, maxMove, m, n) % M;
    }
};