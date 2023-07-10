// Leetcode 650
// [IMP]: DP Knapsack 0/1 Pattern
class Solution {
public:
    int solve(int ans, int prev, int n, vector<vector<int>>& dp){
        // base case
        if(ans == n) return 0;
        if(ans > n) return 1e9;

        // dp check
        if(dp[ans][prev]!=-1) return dp[ans][prev];

        // copyAndPaste operation --> since copying without pasting is of no logic
        int copyAndPaste = 2 + solve(ans+ans, ans, n, dp);

        // paste operation
        int paste = 1e9;
        if(prev > 0) paste = 1 + solve(ans+prev, prev, n, dp);
        
        if(copyAndPaste < 1e9 && paste < 1e9) return dp[ans][prev] = min(copyAndPaste, paste);
        else if(copyAndPaste < 1e9) return dp[ans][prev] = copyAndPaste;
        else if(paste < 1e9) return dp[ans][prev] = paste;
        else return dp[ans][prev] = 1e9;
    }
    int minSteps(int n) {
        // UPDATE: since we are only considered about length of string, hence we don't need to
        // store the string in general
        // memoization:
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        int ans = solve(1, 0, n, dp);
        return ans >= 1e9 ? -1 : ans;
    }
};