class Solution
{
public:
    int countSubstrings(string s)
    {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            int left = i, right = i;
            while (left >= 0 && right < n && s[left] == s[right])
            {
                dp[left][right] = 1;
                left--;
                right++;
            }
            left = i, right = i + 1;
            while (left >= 0 && right < n && s[left] == s[right])
            {
                dp[left][right] = 1;
                left--;
                right++;
            }
        }
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                sum += dp[i][j];
            }
        }
        return sum;
    }
};