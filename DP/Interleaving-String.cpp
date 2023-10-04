// Leetcode 97
// 3D DP
class Solution {
public:
    int dp[101][101][201];
    bool solve(int i, int j, int k, string& s, string& t, string& str){
        // base case
        if(i==s.length() && j==t.length() && k==str.length()) return true;
        // dp check
        if(dp[i][j][k]!=-1) return dp[i][j][k];
        bool ans = false;
        if(s[i]==str[k]){
            ans |= solve(i+1, j, k+1, s, t, str);
        }
        if(t[j]==str[k]){
            ans |= solve(i, j+1, k+1, s, t, str);
        }
        return dp[i][j][k] = ans;
    }
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.length(), m = s2.length();
        if(n+m!=s3.length()) return false;
        // memoization:
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, 0, s1, s2, s3);
    }
};

// 2D DP
class Solution {
public:
    int dp[101][101];
    bool solve(int i, int j, string& s, string& t, string& str){
        // base case
        if(i==s.length() && j==t.length()) return true;
        // dp check
        if(dp[i][j]!=-1) return dp[i][j];
        bool ans = false;
        if(s[i]==str[i+j]){
            ans |= solve(i+1, j, s, t, str);
        }
        if(t[j]==str[i+j]){
            ans |= solve(i, j+1, s, t, str);
        }
        return dp[i][j] = ans;
    }
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.length(), m = s2.length();
        if(n+m!=s3.length()) return false;
        // memoization:
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, s1, s2, s3);
    }
};