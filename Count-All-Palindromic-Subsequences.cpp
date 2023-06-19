class Solution
{
public:
    /*You are required to complete below method */
    long long int countPS(string str)
    {
        // watch pepcoding, guy has tremendous knowledge and explains briefly
        long long n = str.length();
        vector<vector<long long>> dp(n + 1, vector<long long>(n + 1, 0));
        long long mod = 1e9 + 7;
        for (long long a = 0; a < n; a++)
            dp[a][a] = 1;
        for (long long i = n - 1; i >= 0; i--)
        {
            for (long long j = i; j <= n - 1; j++)
            {
                int a = (j > 0) ? dp[i][j - 1] : 0;
                int b = (i < n - 1) ? dp[i + 1][j] : 0;
                if (str[i] == str[j])
                {
                    dp[i][j] = ((a + b) % mod + 1) % mod;
                }
                else
                {
                    int c = (i < n - 1 && j > 0) ? dp[i + 1][j - 1] : 0;
                    dp[i][j] = (((a + b) % mod - c) % mod + mod) % mod;
                }
            }
        }
        return dp[0][n - 1];
    }
};