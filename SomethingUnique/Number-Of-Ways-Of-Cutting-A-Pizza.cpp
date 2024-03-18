// Leetcode 1444

// [IMP] Approach: construction of appledp + top down dp
class Solution {
public:
  const int M = 1e9 + 7;
  long long dp[55][55][15];
  long long solve(int x, int y, int k, int rows, int cols,
                  vector<vector<long long>> &appledp) {
    if (k == 1)
      return appledp[x][y] >= 1;
    if (x >= rows || y >= cols)
      return 0;

    if (dp[x][y][k] != -1)
      return dp[x][y][k];

    long long ans = 0;
    // horizontal cut
    for (int i = x; i < rows; i++) {
      long long upper_slice =
          appledp[x][y] - (i < rows - 1 ? appledp[i + 1][y] : 0);
      long long lower_slice = (i < rows - 1 ? appledp[i + 1][y] : 0);

      if (upper_slice >= 1 && lower_slice >= k - 1) {
        ans += solve(i + 1, y, k - 1, rows, cols, appledp) % M;
        ans %= M;
      }
    }

    // vertical cut
    for (int j = y; j < cols; j++) {
      long long left_slice =
          appledp[x][y] - (j < cols - 1 ? appledp[x][j + 1] : 0);
      long long right_slice = (j < cols - 1 ? appledp[x][j + 1] : 0);

      if (left_slice >= 1 && right_slice >= k - 1) {
        ans += solve(x, j + 1, k - 1, rows, cols, appledp) % M;
        ans %= M;
      }
    }

    return dp[x][y][k] = ans;
  }
  int ways(vector<string> &pizza, int k) {
    int rows = pizza.size(), cols = pizza[0].size();
    // we need to define a 2D array that can give us count of apples
    // from (i, j) to (rows-1, cols-1) in O(1) time
    vector<vector<long long>> appledp(rows, vector<long long>(cols, 0));
    for (int i = rows - 1; i >= 0; i--) {
      for (int j = cols - 1; j >= 0; j--) {
        // we can say
        // appledp[i][j] = (pizza[i][j]=='A') + appledp[i+1][j] +
        // appledp[i][j+1] - appledp[i+1][j+1]
        appledp[i][j] = (pizza[i][j] == 'A');
        if (i < rows - 1)
          appledp[i][j] += appledp[i + 1][j];
        if (j < cols - 1)
          appledp[i][j] += appledp[i][j + 1];
        if (i < rows - 1 && j < cols - 1)
          appledp[i][j] -= appledp[i + 1][j + 1];
        appledp[i][j] %= M;
        appledp[i][j] += M;
        appledp[i][j] %= M;
      }
    }
    memset(dp, -1, sizeof(dp));
    return solve(0, 0, k, rows, cols, appledp);
  }
};