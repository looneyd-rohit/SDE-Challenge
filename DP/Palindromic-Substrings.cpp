// Leetcode 647

// Approach: bottom up dp
class Solution {
public:
  int countSubstrings(string s) {
    int n = s.length();
    vector<vector<int>> dp(n, vector<int>(n, false));
    for (int len = 1; len <= n; len++) {
      for (int i = 0; i + len - 1 < n; i++) {
        int j = i + len - 1;
        if (len == 1)
          dp[i][j] = true;
        else if (len == 2)
          dp[i][j] = s[i] == s[j];
        else
          dp[i][j] = (s[i] == s[j] && dp[i + 1][j - 1]);
      }
    }
    int count = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        count += dp[i][j];
      }
    }
    return count;
  }
};

// Approach 2: classic odd (i, i) and even (i, i+1) approach
class Solution {
public:
  int countSubstrings(string s) {
    int n = s.length();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
      int left = i, right = i;
      while (left >= 0 && right < n && s[left] == s[right]) {
        dp[left][right] = 1;
        left--;
        right++;
      }
      left = i, right = i + 1;
      while (left >= 0 && right < n && s[left] == s[right]) {
        dp[left][right] = 1;
        left--;
        right++;
      }
    }
    int sum = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        sum += dp[i][j];
      }
    }
    return sum;
  }
};