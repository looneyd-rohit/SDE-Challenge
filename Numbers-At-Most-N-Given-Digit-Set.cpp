// Leetcode 902
class Solution
{
public:
    int solve(int len, string &str, vector<int> &digits, bool tight, vector<vector<int>> &dp)
    {
        // base case
        if (len <= 0)
        {
            return 1;
        }

        // dp check
        if (dp[len][tight] != -1)
            return dp[len][tight];

        int ub = tight ? str[str.length() - len] - '0' : digits.back();
        int ans = 0;
        for (int i = 0; i < digits.size(); i++)
        {
            int digit = digits[i];
            // cout<<digit;
            if (digit > ub)
            {
                break;
            }
            else
            {
                ans += solve(len - 1, str, digits, tight && (digit == ub), dp);
            }
        }
        return dp[len][tight] = ans;
    }
    int atMostNGivenDigitSet(vector<string> &digits, int n)
    {
        int sz = digits.size();
        vector<int> numDigits(sz, 0);
        for (int i = 0; i < sz; i++)
        {
            numDigits[i] = digits[i][0] - '0';
        }
        string num = to_string(n);
        int len = num.length();
        // for(auto& e: numDigits) cout<<e<<" ";cout<<endl;
        // memoization:
        vector<vector<int>> dp(len + 1, vector<int>(2, -1));
        int ans = solve(len, num, numDigits, 1, dp);
        // for nos. which are one length shorter than n
        for (int i = 1; i < len; i++)
            ans += pow(sz, i);
        return ans;
    }
};