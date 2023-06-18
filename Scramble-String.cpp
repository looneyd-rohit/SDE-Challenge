class Solution
{
public:
    bool solve(string &s1, string &s2, unordered_map<string, unordered_map<string, bool>> &dp)
    {
        if (s1.length() == 1)
            return s1[0] == s2[0];
        if (s1 == s2)
            return true;

        // dp check
        if (dp.find(s1) != dp.end())
        {
            if (dp[s1].find(s2) != dp[s1].end())
            {
                return dp[s1][s2];
            }
        }

        // try out all partitions
        bool ans = false;
        for (int i = 0; i < s1.length() - 1; i++)
        {
            string leftPartS1 = s1.substr(0, i + 1);
            string rightPartS1 = s1.substr(i + 1, s1.length() - i - 1);
            string leftPartInverseS1 = s1.substr(0, s1.length() - i - 1);
            string rightPartInverseS1 = s1.substr(s1.length() - i - 1, i + 1);
            string leftPartS2 = s2.substr(0, i + 1);
            string rightPartS2 = s2.substr(i + 1, s1.length() - i - 1);

            // we may swap or we may not swap

            // no swap

            bool noSwap = solve(leftPartS1, leftPartS2, dp) && solve(rightPartS1, rightPartS2, dp);

            // swap
            bool swap = solve(rightPartInverseS1, leftPartS2, dp) && solve(leftPartInverseS1, rightPartS2, dp);

            ans = (ans | (noSwap | swap));
            if (ans)
            {
                return dp[s1][s2] = true;
            }
        }
        return dp[s1][s2] = ans;
    }
    bool isScramble(string s1, string s2)
    {
        // we write a function solve(i, j) --> that matches [i...j] portion of
        // strings s1 and s2 and tells whether s2[i...j] is scrambled form of s1[i...j]
        // or not.
        // memoization:
        unordered_map<string, unordered_map<string, bool>> dp;
        return solve(s1, s2, dp);
    }
};