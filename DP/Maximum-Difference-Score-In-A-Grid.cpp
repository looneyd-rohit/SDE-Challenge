// Leetcode 3148

// Approach: find maximum value among all cells in the rectangle from left corner (i, j) to right corner (m-1, n-1)
class Solution {
public:
    int solve(int i, int j, int m, int n, vector<vector<int>>& grid, vector<vector<int>>& dp){
        if(i >= m || j >= n) return -1e9;

        if(dp[i][j]!=-1) return dp[i][j];

        int x = (j+1 < n) ? grid[i][j+1] : -1;
        int y = (i+1 < m) ? grid[i+1][j] : -1;

        int a = max(x, solve(i, j+1, m, n, grid, dp));
        int b = max(y, solve(i+1, j, m, n, grid, dp));

        return dp[i][j] = max(a, b);
    }
    int maxScore(vector<vector<int>>& grid) {
        // we write a function solve() -> that generates the maximum for each
        // rectangle from (i, j) to (m-1, n-1) excluding (i, j)-th cell
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        solve(0, 0, m, n, grid, dp);
        int maxi = INT_MIN;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(dp[i][j]!=-1){
                    maxi = max(maxi, dp[i][j] - grid[i][j]);
                }
            }
        }
        return maxi;
    }
};