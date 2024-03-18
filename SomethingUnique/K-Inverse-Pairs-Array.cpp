// Leetcode 629

// [IMP] Approach 1: top down gives TLE, but bottom up works
class Solution {
public:
  const int M = 1e9 + 7;
  long long dp[1001][1001];
  int solve(int n, int k) {
    if (n == 0)
      return 0;
    if (k == 0)
      return 1;
    if (dp[n][k] != -1)
      return dp[n][k];
    long long ans = 0;
    for (int inv = 0; inv <= min(k, n - 1); inv++) {
      ans += solve(n - 1, k - inv) % M;
      ans %= M;
    }
    return dp[n][k] = ans % M;
  }
  int kInversePairs(int n, int k) {
    // memset(dp, -1, sizeof(dp));
    // return solve(n, k);

    // bottom up approach:
    memset(dp, 0, sizeof(dp));
    // dp[i][j] -> i no. of elements, j no. of inversions
    for (int i = 0; i <= n; i++)
      dp[i][0] = 1;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= k; j++) {
        long long ans = 0;
        for (int inv = 0; inv <= min(j, i - 1); inv++) {
          ans += dp[i - 1][j - inv] % M;
          ans %= M;
        }
        dp[i][j] = ans % M;
      }
    }
    return dp[n][k];
  }
};

// [IMP] Approach 2: bottom up optimization (using prefix sum)
class Solution {
public:
  const int M = 1e9 + 7;
  long long dp[1001][1001];
  int solve(int n, int k) {
    if (n == 0)
      return 0;
    if (k == 0)
      return 1;
    if (dp[n][k] != -1)
      return dp[n][k];
    long long ans = 0;
    for (int inv = 0; inv <= min(k, n - 1); inv++) {
      ans += solve(n - 1, k - inv) % M;
      ans %= M;
    }
    return dp[n][k] = ans % M;
  }
  int kInversePairs(int n, int k) {
    // memset(dp, -1, sizeof(dp));
    // return solve(n, k);

    // bottom up approach:
    memset(dp, 0, sizeof(dp));
    // dp[i][j] -> i no. of elements, j no. of inversions
    for (int i = 0; i <= n; i++)
      dp[i][0] = 1;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= k; j++) {
        int last = j - min(j, i - 1) - 1;
        int first = j;
        // taking the prefix sums to avoid multiple loops
        dp[i][j] +=
            (1LL * dp[i][j - 1] +
             (dp[i - 1][first] - (last >= 0 ? dp[i - 1][last] : 0)) % M) %
            M;
        dp[i][j] %= M;
        dp[i][j] += M;
        dp[i][j] %= M;
      }
    }
    return dp[n][k];
  }
};