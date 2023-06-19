class Solution
{
public:
    unsigned long long solve(int i, int j, int mod, string &s, vector<int> &next, vector<int> &prev, vector<vector<unsigned long long>> &dp)
    {
        // base cases
        if (i == j)
        {
            // string of length = 1
            return 1;
        }
        if (i == j - 1)
        {
            // string of length = 2
            return 2;
        }
        if (i > j)
        {
            return 0;
        }

        // dp check
        if (dp[i][j] != 0)
            return dp[i][j];

        // match found
        if (s[i] == s[j])
        {
            int n = next[i], p = prev[j];
            if (n > p)
            {
                // no elements in between
                return dp[i][j] = (2 * solve(i + 1, j - 1, mod, s, next, prev, dp) % mod + 2) % mod;
            }
            else if (n == p)
            {
                // one element in between
                return dp[i][j] = (2 * solve(i + 1, j - 1, mod, s, next, prev, dp) % mod + 1) % mod;
            }
            else
            {
                // two or more elements in between
                return dp[i][j] = (((2 * solve(i + 1, j - 1, mod, s, next, prev, dp) % mod - solve(n + 1, p - 1, mod, s, next, prev, dp) + mod) % mod) + mod) % mod;
            }
        }
        else
        {
            // (i, j) = (i+1, j) + (i, j-1) - (i+1, j-1)
            return dp[i][j] = ((((solve(i + 1, j, mod, s, next, prev, dp) + solve(i, j - 1, mod, s, next, prev, dp)) % mod - solve(i + 1, j - 1, mod, s, next, prev, dp) + mod) % mod) + mod) % mod;
        }
    }
    int countPalindromicSubsequences(string s)
    {
        int n = s.length();
        int mod = 1e9 + 7;
        vector<int> next(n, -1), prev(n, -1);
        unordered_map<char, int> umap;
        vector<int> hash(26, -1);
        for (int i = 0; i < n; i++)
        {
            char ch = s[i];
            if (umap.find(ch) != umap.end())
            {
                prev[i] = umap[ch];
            }
            else
            {
                prev[i] = -1;
            }
            umap[ch] = i;
        }
        umap.clear();
        for (int i = n - 1; i >= 0; i--)
        {
            char ch = s[i];
            if (umap.find(ch) != umap.end())
            {
                next[i] = umap[ch];
            }
            else
            {
                next[i] = -1;
            }
            umap[ch] = i;
        }
        // memoization:
        // vector<vector<unsigned long long>> dp(n, vector<unsigned long long>(n, 0));
        // return solve(0, n-1, mod, s, next, prev, dp);

        // tabulation:
        vector<vector<unsigned long long>> dp(n + 1, vector<unsigned long long>(n + 1, 0));
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = i; j <= n - 1; j++)
            {
                if (i == j)
                {
                    dp[i][j] = 1;
                    continue;
                }
                if (i == j - 1)
                {
                    dp[i][j] = 2;
                    continue;
                }
                if (i > j)
                {
                    continue;
                }
                // match found
                if (s[i] == s[j])
                {
                    int n = next[i], p = prev[j];
                    if (n > p)
                    {
                        // no elements in between
                        dp[i][j] = (2 * dp[i + 1][j - 1] % mod + 2) % mod;
                    }
                    else if (n == p)
                    {
                        // one element in between
                        dp[i][j] = (2 * dp[i + 1][j - 1] % mod + 1) % mod;
                    }
                    else
                    {
                        // two or more elements in between
                        dp[i][j] = (((2 * dp[i + 1][j - 1] % mod - dp[n + 1][p - 1] + mod) % mod) + mod) % mod;
                    }
                }
                else
                {
                    // (i, j) = (i+1, j) + (i, j-1) - (i+1, j-1)
                    dp[i][j] = ((((dp[i + 1][j] + dp[i][j - 1]) % mod - dp[i + 1][j - 1] + mod) % mod) + mod) % mod;
                }
            }
        }
        return dp[0][n - 1];
    }
};