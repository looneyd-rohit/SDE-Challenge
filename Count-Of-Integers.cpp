// Leetcode 2719
class Solution
{
public:
    const int M = 1e9 + 7;
    int solve(int len, string &str, bool tight, int sum, int maxi, int mini, vector<vector<vector<int>>> &dp)
    {
        // base case
        if (len == 0)
        {
            if (sum >= mini && sum <= maxi)
                return 1;
            return 0;
        }

        if (sum > 400)
            return 0;

        // dp check
        if (dp[len][sum][tight] != -1)
            return dp[len][sum][tight];

        int ub = tight ? str[str.length() - len] - '0' : 9;

        int ans = 0;
        for (int digit = 0; digit <= ub; digit++)
        {
            ans += solve(len - 1, str, tight & (digit == ub), sum + digit, maxi, mini, dp) % M;
            ans = ans % M;
        }
        return dp[len][sum][tight] = ans % M;
    }
    bool computeSum(string &str, int maxi, int mini)
    {
        int sum = 0;
        for (auto &e : str)
            sum += e - '0';
        return (sum >= mini && sum <= maxi);
    }
    int count(string num1, string num2, int min_sum, int max_sum)
    {
        int n1 = num1.length(), n2 = num2.length();
        // memoization:
        vector<vector<vector<int>>> dp1(max(n1, n2) + 1, vector<vector<int>>(401, vector<int>(2, -1)));
        vector<vector<vector<int>>> dp2(max(n1, n2) + 1, vector<vector<int>>(401, vector<int>(2, -1)));
        int lb = solve(n1, num1, 1, 0, max_sum, min_sum, dp1);
        int ub = solve(n2, num2, 1, 0, max_sum, min_sum, dp2);
        return ((1LL * ub - lb + M) % M + computeSum(num1, max_sum, min_sum) + M) % M;
    }
};