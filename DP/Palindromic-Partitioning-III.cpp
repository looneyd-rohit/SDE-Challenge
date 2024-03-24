// Leetcode 1278

// Approach: khandani palindromic substring precompute table generation and
// solving with dp subsequently
class Solution {
public:
  vector<vector<int>> changedp;
  void precompute(string &s) {
    int n = s.length();
    for (int i = 0; i < n; i++) {
      int left = i, right = i;
      while (left >= 0 && right < n) {
        if (s[left] != s[right]) {
          // cout<<left<<", "<<right<<endl;
          changedp[left][right] = 1 + changedp[left + 1][right - 1];
        } else {
          if (left != right) {
            changedp[left][right] = changedp[left + 1][right - 1];
          }
        }
        left--;
        right++;
      }
      left = i, right = i + 1;
      while (left >= 0 && right < n) {
        if (s[left] != s[right]) {
          // cout<<left<<", "<<right<<endl;
          if (left == i && right == i + 1) {
            changedp[left][right] = 1;
          } else {
            changedp[left][right] = 1 + changedp[left + 1][right - 1];
          }
        } else {
          changedp[left][right] = changedp[left + 1][right - 1];
        }
        left--;
        right++;
      }
    }
  }
  int dp[501][501];
  int solve(int index, int k, int n, string &s, vector<vector<int>> &changedp) {
    if (index >= n) {
      if (k == 0)
        return 0;
      return 1e9;
    }

    if (k == 0)
      return 1e9;

    if (dp[index][k] != -1)
      return dp[index][k];

    // form all palindromes from
    int ans = 1e9;
    for (int i = index; i < n; i++) {
      ans = min(
          ans, (int)(changedp[index][i] + solve(i + 1, k - 1, n, s, changedp)));
    }
    return dp[index][k] = ans;
  }
  int palindromePartition(string s, int k) {
    int n = s.length();
    changedp.resize(n + 1, vector<int>(n + 1, 0));
    // first compute for every substring of s how many characters
    // need to be changed to be changed to make it palindrome
    precompute(s);
    memset(dp, -1, sizeof(dp));
    return solve(0, k, n, s, changedp);
  }
};