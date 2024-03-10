// Leetcode 45

// Approach: top down + bottom up
class Solution {
public:
  int dp[(int)1e4 + 1];
  int solve(int index, int n, vector<int> &nums) {
    if (index >= n - 1)
      return 0;

    if (dp[index] != -1)
      return dp[index];

    int jump_len = nums[index];
    int ans = 1e9;
    for (int len = 1; len <= jump_len; len++) {
      ans = min(ans, 1 + solve(index + len, n, nums));
    }
    return dp[index] = ans;
  }
  int jump(vector<int> &nums) {
    int n = nums.size();
    // memset(dp, -1, sizeof(dp));
    // return solve(0, n, nums);

    // bottom up
    memset(dp, 0, sizeof(dp));
    for (int index = n - 2; index >= 0; index--) {
      int jump_len = nums[index];
      int ans = 1e9;
      for (int len = 1; len <= jump_len; len++) {
        ans = min(ans, 1 + (index + len >= n ? 0 : dp[index + len]));
      }
      dp[index] = ans;
    }
    return dp[0];
  }
};