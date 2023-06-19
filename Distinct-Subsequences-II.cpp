// Approach 1: Brute Force
class Solution
{
public:
    int solve(int index, int last, int mod, string &s, vector<vector<int>> &dp)
    {
        // base case
        if (index == s.length())
        {
            // return 1 if non empty, else return 0;
            return (last != -1);
        }

        // dp check
        if (dp[index][last + 1] != -1)
            return dp[index][last + 1];

        // logic: only append characters to end of subsequence and when any character
        // is not taken then don't take if it appears further as the last character
        // for string "abb"
        // i=0 --> "" , "a"
        // i=1 --> "b", "ab"
        // i=2 --> "bb", "abb" [we have the option to append 'b' to "", "a", "b", "ab"]
        // but we only append 'b' to "b" and "ab", since 'b' was not taken in "" or "a"
        // we don't take it further
        int pick = solve(index + 1, s[index] - 'a', mod, s, dp);

        int notPick = 0;
        if (last == -1 || last != s[index] - 'a')
        {
            notPick = solve(index + 1, last, mod, s, dp);
        }

        return dp[index][last + 1] = (pick + notPick) % mod;
    }
    int distinctSubseqII(string s)
    {
        int n = s.length();
        int mod = 1e9 + 7;
        // memoization:
        // vector<vector<int>> dp(n, vector<int>(27, -1));
        // return (solve(0, -1, mod, s, dp) + mod*1LL) % mod;

        // tabulation:
        vector<vector<int>> dp(n + 1, vector<int>(27, 1));
        dp[n][0] = 0;
        for (int index = n - 1; index >= 0; index--)
        {
            for (int last = 25; last >= -1; last--)
            {
                int pick = dp[index + 1][s[index] - 'a' + 1];
                ;

                int notPick = 0;
                if (last == -1 || last != s[index] - 'a')
                {
                    notPick = dp[index + 1][last + 1];
                }

                dp[index][last + 1] = (pick + notPick) % mod;
            }
        }
        return dp[0][0];
    }
};

// Approach 2: Maths based
class Solution
{
public:
    int distinctSubseqII(string s)
    {
        // approach by pepcoding
        int n = s.length();
        int mod = 1e9 + 7;
        unordered_map<char, int> umap;
        vector<int> dp(n + 1, 0);
        // considering empty as one subsequence
        dp[0] = 1;
        for (int i = 1; i <= n; i++)
        {
            char ch = s[i - 1];
            int cnt = (dp[i - 1] * 2) % mod;
            if (umap.find(ch) == umap.end())
            {
                dp[i] = cnt;
            }
            else
            {
                dp[i] = ((cnt - dp[umap[ch] - 1]) % mod + mod) % mod;
            }
            umap[ch] = i;
        }
        return ((dp[n] - 1) % mod + mod) % mod;
    }
};