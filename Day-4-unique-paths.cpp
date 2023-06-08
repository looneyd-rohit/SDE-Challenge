class Solution {
public:
    int solve(int i, int j, int m, int n, vector<vector<int>>& dp){
        // boundary check
        if(i<0 || j<0 || i>=m || j>=n) return 0;

        // base case
        if(i==0 && j==0) return 1;

        // dp check
        if(dp[i][j]!=-1) return dp[i][j];

        // up
        int up = solve(i-1, j, m, n, dp);

        // left
        int left = solve(i, j-1, m, n, dp);

        return dp[i][j] = (up + left);
    }
    int uniquePaths(int m, int n) {
        // memoization:
        // vector<vector<int>> dp(m, vector<int>(n, -1));
        // int ans = solve(m-1, n-1, m, n, dp);
        // return ans;

        // // tabulation:
        // vector<vector<int>> dp(m, vector<int>(n, 0));
        // dp[0][0] = 1;
        // for(int i=0; i<m; i++){
        // 	for(int j=0; j<n; j++){
        // 		if(i==0 && j==0){
        // 			dp[i][j] = 1;
        // 		}else{
        // 			// up
        // 			int up = 0;
        // 			if(i>=1) up = dp[i-1][j];

        // 			// left
        // 			int left = 0;
        // 			if(j>=1) left = dp[i][j-1];

        // 			dp[i][j] = (up + left);
        // 		}
        // 	}
        // }
        // return dp[m-1][n-1];

        // space optimization:
        vector<int> dp1(n, 0);
        vector<int> dp2(n, 0);
        dp1[0] = 1;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i==0 && j==0){
                    dp2[j] = 1;
                }else{
                    // up
                    int up = 0;
                    if(i>=1) up = dp1[j];

                    // left
                    int left = 0;
                    if(j>=1) left = dp2[j-1];

                    dp2[j] = (up + left);
                }
            }
            dp1 = dp2;
        }
        return dp1[n-1];
    }
};