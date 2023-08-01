// Leetcode 712

class Solution {
public:
    int solve(int i, int j, string& s, string& t, vector<vector<int>>& dp){
        // base case
        if(i < 0 || j < 0){
            int sum = 0;
            if(i < 0){
                for(int k=0; k<=j; k++) sum += t[k];
            }else if(j < 0){
                for(int k=0; k<=i; k++) sum += s[k];
            }
            return sum;
        }

        // dp check
        if(dp[i][j]!=-1) return dp[i][j];

        // if equal
        if(s[i] == t[j]){
            // equal no deletion required
            return dp[i][j] = solve(i-1, j-1, s, t, dp);
        }else{
            // not equal deletion required
            int a = (int)(s[i]) + solve(i-1, j, s, t, dp);
            int b = (int)(t[j]) + solve(i, j-1, s, t, dp);
            return dp[i][j] = min(a, b);
        }
    }
    int minimumDeleteSum(string s1, string s2) {
        // may be it can done, by removing the lcs and taking sum of the remaining
        // elements in the array
        int n = s1.length(), m = s2.length();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        int mini = solve(n-1, m-1, s1, s2, dp);
        return mini;
    }
};