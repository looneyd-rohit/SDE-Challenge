class Solution
{
public:
    string longestPalindrome(string s)
    {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        int maxi = 0, ii, jj;
        for (int i = 0; i < n; i++)
        {
            int left = i, right = i;
            while (left >= 0 && right < n)
            {
                if (left == right)
                {
                    dp[left][right] = 1;
                }
                else if (s[left] == s[right])
                {
                    if (dp[left + 1][right - 1] == 0)
                    {
                        dp[left][right] = 0;
                    }
                    else
                    {
                        dp[left][right] = 2 + dp[left + 1][right - 1];
                    }
                }
                else
                {
                    dp[left][right] = 0;
                }
                if (dp[left][right] > maxi)
                {
                    maxi = dp[left][right];
                    ii = left;
                    jj = right;
                }
                left--;
                right++;
            }
            left = i, right = i + 1;
            while (left >= 0 && right < n)
            {
                if (right - left == 1)
                {
                    if (s[left] == s[right])
                        dp[left][right] = 2;
                    else
                        dp[left][right] = 0;
                }
                else if (s[left] == s[right])
                {
                    if (dp[left + 1][right - 1] == 0)
                    {
                        dp[left][right] = 0;
                    }
                    else
                    {
                        dp[left][right] = 2 + dp[left + 1][right - 1];
                    }
                }
                else
                {
                    dp[left][right] = 0;
                }
                if (dp[left][right] > maxi)
                {
                    maxi = dp[left][right];
                    ii = left;
                    jj = right;
                }
                left--;
                right++;
            }
        }
        return s.substr(ii, jj - ii + 1);
    }
};