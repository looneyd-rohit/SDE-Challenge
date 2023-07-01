// Leetcode 2304
// https://leetcode.com/problems/minimum-path-cost-in-a-grid/

class Solution {
public:
    int solve(int i, int j, int m, int n, vector<vector<int>>& grid, vector<vector<int>>& moveCost, vector<vector<int>>& dp){
        // base case
        if(i == m-1){
            return grid[i][j];
        }

        // dp check
        if(dp[i][j]!=-1) return dp[i][j];

        int currentCellId = grid[i][j];
        // we can go from current cell to any next cell
        int ans = 1e9;
        for(int j=0; j<n; j++){
            ans = min(ans, currentCellId + moveCost[currentCellId][j] + solve(i+1, j, m, n, grid, moveCost, dp));
        }
        return dp[i][j] = ans;
    }
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int m = grid.size(), n = grid[0].size();
        int ans = 1e9;
        // memoization:
        vector<vector<int>> dp(51, vector<int>(51, -1));
        for(int j=0; j<n; j++){
            ans = min(ans, solve(0, j, m, n, grid, moveCost, dp));
        }
        return ans;
    }
};