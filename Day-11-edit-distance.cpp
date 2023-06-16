class Solution
{
public:
    int solve(int index1, int index2, string &s, string &t, vector<vector<int>> &dp)
    {
        // base case
        if (index1 < 0)
        {
            // if index2 == -1 --> 0 operations, if index2 >=0 then according operations
            return index2 + 1;
        }

        if (index2 < 0)
        {
            return index1 + 1;
        }

        // dp check
        if (dp[index1][index2] != -1)
            return dp[index1][index2];

        // match
        if (s[index1] == t[index2])
        {
            // when match no operations needed
            return dp[index1][index2] = solve(index1 - 1, index2 - 1, s, t, dp);
        }
        // not match
        else
        {
            // when no match we require operations

            // insert on s
            int a = 1 + solve(index1, index2 - 1, s, t, dp);

            // delete on s
            int b = 1 + solve(index1 - 1, index2, s, t, dp);

            // replace on s
            int c = 1 + solve(index1 - 1, index2 - 1, s, t, dp);

            return dp[index1][index2] = min({a, b, c});
        }
    }
    int minDistance(string word1, string word2)
    {
        int n = word1.size(), m = word2.size();
        // memoization:
        // vector<vector<int>> dp(n, vector<int>(m, -1));
        // return solve(n-1, m-1, word1, word2, dp);

        // // tabulation:
        // vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        // for(int index2=1; index2<=m; index2++){
        //     // no index1+1 since we already shifted index by 1 which now represents length
        //     dp[0][index2] = index2;
        // }
        // // since index1=0 && index2==0 gets catched by first base case only
        // for(int index1=1; index1<=n; index1++){
        //     // no index2+1 since we already shifted index by 1 which now represents length
        //     dp[index1][0] = index1;
        // }

        // for(int index1=1; index1<=n; index1++){
        //     for(int index2=1; index2<=m; index2++){
        //         // match
        //         if(word1[index1-1] == word2[index2-1]){
        //             // when match no operations needed
        //             dp[index1][index2] = dp[index1-1][index2-1];
        //         }
        //         // not match
        //         else{
        //             // when no match we require operations

        //             // insert on s
        //             int a = 1 + dp[index1][index2-1];

        //             // delete on s
        //             int b = 1 + dp[index1-1][index2];

        //             // replace on s
        //             int c = 1 + dp[index1-1][index2-1];

        //             dp[index1][index2] = min({a, b, c});
        //         }
        //     }
        // }
        // return dp[n][m];

        // space optimization:
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        vector<int> dp1(m + 1, 0);
        vector<int> dp2(m + 1, 0);
        for (int index2 = 1; index2 <= m; index2++)
        {
            // no index1+1 since we already shifted index by 1 which now represents length
            dp1[index2] = index2;
        }
        for (int index1 = 1; index1 <= n; index1++)
        {
            dp2[0] = index1;
            for (int index2 = 1; index2 <= m; index2++)
            {
                // match
                if (word1[index1 - 1] == word2[index2 - 1])
                {
                    // when match no operations needed
                    dp2[index2] = dp1[index2 - 1];
                }
                // not match
                else
                {
                    // when no match we require operations

                    // insert on s
                    int a = 1 + dp2[index2 - 1];

                    // delete on s
                    int b = 1 + dp1[index2];

                    // replace on s
                    int c = 1 + dp1[index2 - 1];

                    dp2[index2] = min({a, b, c});
                }
            }
            dp1 = dp2;
        }
        return dp1[m];
    }
};