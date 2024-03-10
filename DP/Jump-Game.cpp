// Leetcode 55

// Approach: top down + bottom up
class Solution {
public:
  int dp[(int)1e4 + 1];
  bool solve(int index, int n, vector<int> &nums) {
    if (index >= n - 1)
      return true;

    if (dp[index] != -1)
      return dp[index];

    int jump_len = nums[index];
    bool ans = false;
    for (int len = 1; len <= jump_len; len++) {
      ans = ans | solve(index + len, n, nums);
      if (ans)
        return dp[index] = ans;
    }
    return dp[index] = ans;
  }
  bool canJump(vector<int> &nums) {
    int n = nums.size();
    // memset(dp, -1, sizeof(dp));
    // return solve(0, n, nums);

    // bottom up
    memset(dp, false, sizeof(dp));
    dp[0] = true;
    for (int i = 1; i < n; i++) {
      for (int j = 0; j < i; j++) {
        if (dp[j] && (j + nums[j] >= i)) {
          dp[i] = true;
          break;
        }
      }
      if (dp[i] == false)
        return false;
    }
    return dp[n - 1];
  }
};

// [IMP] Approach: linear solution (tricky)
class Solution {
public:
  bool canJump(vector<int> &nums) {
    int n = nums.size();
    int max_reachable = 0; // maximum reachable index
    for (int i = 0; i < n; i++) {
      if (i > max_reachable)
        return false; // if index surpasses max_reachable
                      // then we cannot reach
      max_reachable = max(max_reachable, i + nums[i]);
    }
    return true;
  }
};