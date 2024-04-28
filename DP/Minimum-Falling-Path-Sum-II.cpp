// Leetcode 1289

// Approach: 2d dp approach
class Solution {
public:
    int dp[201][201];
    int solve(int row, int prev, int m, int n, vector<vector<int>>& grid){
        if(row == m) return 0;

        if(dp[row][prev+1]!=-1) return dp[row][prev+1];

        int ans = 1e9;
        for(int col=0; col<n; col++){
            if(col == prev) continue;
            ans = min(ans, grid[row][col] + solve(row+1, col, m, n, grid));
        }
        return dp[row][prev+1] = ans;
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        memset(dp, -1, sizeof(dp));
        return solve(0, -1, m, n, grid);
    }
};