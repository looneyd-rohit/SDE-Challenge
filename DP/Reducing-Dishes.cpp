// Leetcode 1402

// [IMP] Approach: bottom up requires some brain work
class Solution {
public:
  long long dp[505][505];
  int solve(int time, int index, int n, vector<int> &satisfaction) {
    // base case
    if (index >= n)
      return 0;

    if (dp[time][index] != -1)
      return dp[time][index];

    // cook the dish
    int cook = time * satisfaction[index] +
               solve(time + 1, index + 1, n, satisfaction);

    // don't cook the dish
    int dont_cook = 0 + solve(time, index + 1, n, satisfaction);

    return dp[time][index] = max(cook, dont_cook);
  }
  int maxSatisfaction(vector<int> &satisfaction) {
    int n = satisfaction.size();
    sort(begin(satisfaction), end(satisfaction));
    // memset(dp, -1, sizeof(dp));
    // return solve(1, 0, n, satisfaction);

    // bottom up dp:
    // state: dp[i][j] --> satisfaction at [i-th time] when upto [j-th dishes]
    // are cooked (may or may not be all cooked)
    // (i, j) --> depends on (i, j-1) (dont cook) and (i-1, j-1) (cooked)
    // memset(dp, INT_MIN, sizeof(dp));
    // at time = 0 all have 0 satisfaction
    vector<vector<long long>> dp2(501, vector<long long>(501, INT_MIN));
    for (int i = 0; i <= n; i++) {
      dp2[0][i] = 0;
    }

    dp2[1][1] = satisfaction[0];

    for (int time = 1; time <= n; time++) {
      for (int i = 2; i <= n; i++) {
        long long include = satisfaction[i - 1] * time + dp2[time - 1][i - 1];

        long long exclude = 0 + dp2[time][i - 1];

        dp2[time][i] = max(include, exclude);
      }
    }

    long long ans = 0;
    for (int time = 0; time <= n; time++) {
      ans = max(ans, dp2[time][n]);
    }

    return ans;
  }
};