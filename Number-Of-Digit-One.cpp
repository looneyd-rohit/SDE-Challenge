// Leetcode 233
class Solution
{
public:
    int cnt(int len, string &str, bool tight)
    {
        // base case
        if (tight == 0)
            return pow(10, len);

        if (len == 0)
            return 1;

        int ub = tight ? str[str.length() - len] - '0' : 9;
        int ans = 0;
        for (int digit = 0; digit <= ub; digit++)
        {
            ans += cnt(len - 1, str, tight & (digit == ub));
        }
        return ans;
    }
    int solve(int len, string &str, bool tight, vector<vector<int>> &dp)
    {
        // base case
        if (len == 0)
        {
            return 0;
        }

        // dp check
        if (dp[len][tight] != -1)
            return dp[len][tight];

        int ub = tight ? str[str.length() - len] - '0' : 9;
        int ans = 0;
        for (int digit = 0; digit <= ub; digit++)
        {
            if (digit == 1)
            {
                ans += cnt(len - 1, str, tight & (digit == ub));
            }
            ans += solve(len - 1, str, tight & (digit == ub), dp);
        }
        return dp[len][tight] = ans;
    }
    int countDigitOne(int n)
    {
        string num = to_string(n);
        int len = num.length();
        // memoization:
        vector<vector<int>> dp(len + 1, vector<int>(2, -1));
        return solve(len, num, 1, dp);
    }
};