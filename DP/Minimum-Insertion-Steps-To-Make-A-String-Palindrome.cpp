// Leetcode 1312

// Approach: lcs based
class Solution {
public:
  int dp[501][501];
  int solve(int i, int j, string &s, string &t) {
    if (i == 0 || j == 0) {
      // s --> ended
      return 0;
    }

    if (dp[i][j] != -1)
      return dp[i][j];

    if (s[i - 1] == t[j - 1]) {
      return dp[i][j] = 1 + solve(i - 1, j - 1, s, t);
    } else {
      return dp[i][j] = max({solve(i - 1, j, s, t), solve(i, j - 1, s, t)});
    }
  }
  int minInsertions(string s) {
    // get the lcs of the string and its reverse
    // the remaining length needs to have its counter part
    // and hence will be the answer
    int n = s.length();
    string t = s;
    reverse(begin(t), end(t));
    memset(dp, -1, sizeof(dp));
    int lcs = solve(n, n, s, t);
    return (n - lcs);
  }
};