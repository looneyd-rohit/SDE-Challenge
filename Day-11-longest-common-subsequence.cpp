class Solution
{
public:
    int solve(int index1, int index2, string &s, string &t, vector<vector<int>> &dp)
    {
        // base case
        if (index1 == -1)
        {
            // string s went out of bounds
            return 0;
        }

        if (index2 == -1)
        {
            // string t went out of bounds
            return 0;
        }

        // dp check
        if (dp[index1][index2] != -1)
            return dp[index1][index2];

        // match
        if (s[index1] == t[index2])
        {
            return dp[index1][index2] = 1 + solve(index1 - 1, index2 - 1, s, t, dp);
        }
        // not match
        else
        {
            int a = solve(index1 - 1, index2, s, t, dp);
            int b = solve(index1, index2 - 1, s, t, dp);
            return dp[index1][index2] = max(a, b);
        }
    }
    int longestCommonSubsequence(string text1, string text2)
    {
        int n1 = text1.size(), n2 = text2.size();
        // memoization:
        // vector<vector<int>> dp(n1, vector<int>(n2, -1));
        // return solve(n1-1, n2-1, text1, text2, dp);

        // // tabulation:
        // vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));
        // for(int index1=1; index1<=n1; index1++){
        //     for(int index2=1; index2<=n2; index2++){
        //         // match
        //         if(text1[index1-1] == text2[index2-1]){
        //             dp[index1][index2] = 1 + dp[index1-1][index2-1];
        //         }
        //         // not match
        //         else{
        //             int a = dp[index1-1][index2];
        //             int b = dp[index1][index2-1];
        //             dp[index1][index2] = max(a, b);
        //         }
        //     }
        // }
        // return dp[n1][n2];

        // space optimization:
        vector<int> dp1(n2 + 1, 0);
        vector<int> dp2(n2 + 1, 0);
        for (int index1 = 1; index1 <= n1; index1++)
        {
            for (int index2 = 1; index2 <= n2; index2++)
            {
                // match
                if (text1[index1 - 1] == text2[index2 - 1])
                {
                    dp2[index2] = 1 + dp1[index2 - 1];
                }
                // not match
                else
                {
                    int a = dp1[index2];
                    int b = dp2[index2 - 1];
                    dp2[index2] = max(a, b);
                }
            }
            dp1 = dp2;
        }
        return dp1[n2];
    }
};