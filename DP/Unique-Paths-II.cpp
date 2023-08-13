// Leetcode 63

class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& obstacleGrid, vector<vector<int>>& dp){
        // base case
        if(i < 0 || j < 0) return 0;

        if(obstacleGrid[i][j] == 1) return 0;
        
        if(i == 0 && j == 0) return 1;

        // dp check
        if(dp[i][j]!=-1) return dp[i][j];

        // left
        int left = solve(i, j-1, obstacleGrid, dp);
        
        // up
        int up = solve(i-1, j, obstacleGrid, dp);

        return dp[i][j] = (left + up);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        if(obstacleGrid[m-1][n-1]==1) return 0;
        // memoization:
        vector<vector<int>> dp(m, vector<int>(n, 0));
        // return solve(m-1, n-1, obstacleGrid, dp);

        // // tabulation:
        // for(int i=0; i<m; i++){
        //     for(int j=0; j<n; j++){
        //         if(i == 0 && j == 0 && obstacleGrid[i][j]==0){
        //             dp[i][j] = 1;
        //         }else{
        //             if(obstacleGrid[i][j] == 1){
        //                 dp[i][j] = 0;
        //             }else{
        //                 // left
        //                 int left = 0;
        //                 if(j >= 1){
        //                     left = dp[i][j-1];
        //                 }
                        
        //                 // up
        //                 int up = 0;
        //                 if (i >= 1) {
        //                     up = dp[i-1][j];
        //                 }

        //                 dp[i][j] = (left + up);
        //             }
        //         }
        //     }
        // }
        // return dp[m-1][n-1];

        // space optimization:
        vector<int> dp1(n, 0);
        vector<int> dp2(n, 0);
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i == 0 && j == 0 && obstacleGrid[i][j]==0){
                    dp2[j] = 1;
                }else{
                    if(obstacleGrid[i][j] == 1){
                        dp2[j] = 0;
                    }else{
                        // left
                        int left = 0;
                        if(j >= 1){
                            left = dp2[j-1];
                        }
                        
                        // up
                        int up = 0;
                        if (i >= 1) {
                            up = dp2[j];
                        }

                        dp2[j] = (left + up);
                    }
                }
            }
            dp1 = dp2;
        }
        return dp1[n-1];
    }
};