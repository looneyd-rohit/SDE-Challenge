// Leetcode 600
class Solution
{
public:
    int solve(int len, string &num, bool tight, int prev, vector<vector<vector<int>>> &dp)
    {
        // base case
        if (len == 0)
        {
            return 1;
        }

        // dp check
        if (dp[len][prev][tight] != -1)
            return dp[len][prev][tight];

        int ub = tight ? num[num.length() - len] - '0' : 1;
        int ans = 0;
        for (int digit = 0; digit <= ub; digit++)
        {
            if (prev == 0)
            {
                ans += solve(len - 1, num, tight & (digit == ub), digit, dp);
            }
            else
            {
                if (digit == 0)
                {
                    ans += solve(len - 1, num, tight & (digit == ub), digit, dp);
                }
            }
        }
        return dp[len][prev][tight] = ans;
    }
    int findIntegers(int n)
    {
        string num = "";
        while (n)
        {
            num.push_back((char)((n & 1) + '0'));
            n = n >> 1;
        }
        reverse(begin(num), end(num));
        int len = num.length();
        // memoization:
        vector<vector<vector<int>>> dp(32, vector<vector<int>>(2, vector<int>(2, -1)));
        return solve(len, num, 1, 0, dp);
    }
};