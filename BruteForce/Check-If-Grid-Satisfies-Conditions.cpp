// Leetcode 3142

// Approach: applied dp, but can be done with brute force
class Solution {
public:
    int store[1001][11];
    int solve(int i, int j, int n, vector<vector<int>>& dp){
        if(i == n) return 0;
        if(store[i][j+1]!=-1) return store[i][j+1];
        int ans = 1e9;
        for(int col=0; col<10; col++){
            if(col!=j){
                ans = min(ans, dp[i][col] + solve(i+1, col, n, dp));
            }
        }
        return store[i][j+1] = ans;
    }
    bool satisfiesConditions(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(10, 0));
        memset(store, -1, sizeof(store));
        for(int num=0; num<=9; num++){
            for(int j=0; j<n; j++){
                int count = 0;
                for(int i=0; i<m; i++){
                    if(grid[i][j]!=num){
                        count++;
                    }
                }
                dp[j][num] = count;
            }
        }
        return solve(0, -1, n, dp) == 0;
    }
};