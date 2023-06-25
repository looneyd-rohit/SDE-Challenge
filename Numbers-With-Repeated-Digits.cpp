// Leetcode 1012
class Solution
{
public:
    int solve(int len, string &str, bool tight, int mask, bool isRepeated, vector<vector<vector<vector<int>>>> &dp)
    {
        // base case
        if (len == 0)
        {
            return isRepeated;
        }

        // dp check
        if (dp[len][tight][isRepeated][mask] != -1)
            return dp[len][tight][isRepeated][mask];

        int ub = tight ? str[str.length() - len] - '0' : 9;
        int ans = 0;
        for (int digit = 0; digit <= ub; digit++)
        {
            if (mask == 0)
            {
                if (digit == 0)
                {
                    // mask is 0 and digit is 0, so number not started yet
                    ans += solve(len - 1, str, tight & (digit == ub), mask, 0, dp);
                }
                else
                {
                    // mask is 0 and digit is not 0, so number just started
                    ans += solve(len - 1, str, tight & (digit == ub), mask | (1 << digit), isRepeated, dp);
                }
            }
            else
            {
                if (mask & (1 << digit))
                {
                    // mask is not 0 and digit is repeated, so repeated marked true
                    ans += solve(len - 1, str, tight & (digit == ub), mask, true, dp);
                }
                else
                {
                    // mask is not 0 and digit is not repeated, so repeated marked as it was
                    ans += solve(len - 1, str, tight & (digit == ub), mask | (1 << digit), isRepeated, dp);
                }
            }
        }
        return dp[len][tight][isRepeated][mask] = ans;
    }
    int numDupDigitsAtMostN(int n)
    {
        string num = to_string(n);
        int len = num.length();
        // memoization:
        vector<vector<vector<vector<int>>>> dp(len + 1, vector<vector<vector<int>>>(2, vector<vector<int>>(2, vector<int>(1025, -1))));
        return solve(len, num, 1, 0, 0, dp);
    }
};