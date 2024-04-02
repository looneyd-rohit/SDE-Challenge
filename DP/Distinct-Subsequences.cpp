// Leetcode 115

class Solution {
public:
    int dp[1001][1001];
    int solve(int i, int j, int n, int m, string& s, string& t){
        // base cases
        if(j >= m) return 1;
        if(i >= n) return 0;

        // dp check
        if(dp[i][j]!=-1) return dp[i][j];

        if(s[i]==t[j]){
            // either match with i-th character of s or don't (try later)
            return dp[i][j] = solve(i+1, j+1, n, m, s, t) + solve(i+1, j, n, m, s, t);
        }else{
            return dp[i][j] = solve(i+1, j, n, m, s, t);
        }
    }
    int numDistinct(string s, string t) {
        int n = s.length(), m = t.length();
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, n, m, s, t);
    }
};