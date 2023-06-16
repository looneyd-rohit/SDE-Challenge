class Solution
{
public:
    bool isPalindrome(string &s, int start, int end)
    {
        // cout<<s.substr(start, end-start+1)<<endl;
        for (int i = start, j = end; i < j; i++, j--)
        {
            if (s[i] != s[j])
            {
                return false;
            }
        }
        return true;
    }
    int solve(int index, string &s, vector<int> &dp)
    {
        // base case
        if (index >= s.length())
        {
            return 0;
        }

        // dp check
        if (dp[index] != -1)
            return dp[index];

        // redundant call check
        if (isPalindrome(s, index, s.length() - 1))
            return dp[index] = 1;

        int ans = 1e9;
        // placing the partion at various indexes
        for (int i = index; i < s.length(); i++)
        {
            // we don't need the actual strings, so we don't make substrings --> just check
            // for palindrome
            int start = index, end = i;
            if (isPalindrome(s, start, end))
            {
                ans = min(ans, 1 + solve(i + 1, s, dp));
            }
        }
        return dp[index] = ans;
    }
    int minCut(string s)
    {
        // similar to palindrome partitioning:
        int n = s.length();
        // we can remove ovelapping subproblems:
        // memoization:
        // vector<int> dp(n, -1);
        // return solve(0, s, dp) - 1;

        // tabulation:
        vector<int> dp(n + 1, 0);
        for (int index = n - 1; index >= 0; index--)
        {
            // redundant call check
            if (isPalindrome(s, index, s.length() - 1))
            {
                dp[index] = 1;
                continue;
            }

            int ans = 1e9;
            // placing the partion at various indexes
            for (int i = index; i < s.length(); i++)
            {
                // we don't need the actual strings, so we don't make substrings --> just check
                // for palindrome
                int start = index, end = i;
                if (isPalindrome(s, start, end))
                {
                    ans = min(ans, 1 + dp[i + 1]);
                }
            }
            dp[index] = ans;
        }
        return dp[0] - 1;
    }
};