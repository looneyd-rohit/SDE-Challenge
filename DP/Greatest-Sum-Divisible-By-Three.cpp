// Leetcode 1262

// Approach: dp take / not take approach
class Solution {
public:
  int dp[(int)4e4 + 1][3];
  int solve(int index, int rem, int n, vector<int> &nums) {
    if (index == n) {
      if (rem == 0)
        return 0;
      return -1e9;
    }

    if (dp[index][rem] != -1)
      return dp[index][rem];

    // take
    int take = nums[index] + solve(index + 1, (rem + nums[index]) % 3, n, nums);

    // not take
    int not_take = 0 + solve(index + 1, rem, n, nums);

    return dp[index][rem] = max(take, not_take);
  }
  int maxSumDivThree(vector<int> &nums) {
    int n = nums.size();
    memset(dp, -1, sizeof(dp));
    return solve(0, 0, n, nums);
  }
};