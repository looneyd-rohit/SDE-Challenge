// Leetcode 3077

// Approach 1: top down
class Solution {
public:
  vector<vector<vector<long long>>> dp;
  long long solve(int index, long long k, bool empty, vector<int> &nums) {
    // base case
    if (k == 0)
      return 0;
    if (index == nums.size())
      return -1e18;

    // dp check
    if (dp[index][k][empty] != -1)
      return dp[index][k][empty];

    long long not_take = -1e18;

    if (empty) { // if empty we can either take or skip
      not_take = solve(index + 1, k, true, nums); // skip
    }

    // take and make new subarray
    // or
    // take and continue current subarray
    long long take = -1e18;

    if (k % 2 == 1) {
      take = solve(index + 1, k - 1, true, nums) + nums[index] * k;
      take = max(take, solve(index + 1, k, false, nums) + nums[index] * k);
    } else {
      take = solve(index + 1, k - 1, true, nums) - nums[index] * k;
      take = max(take, solve(index + 1, k, false, nums) - nums[index] * k);
    }

    return dp[index][k][empty] = max({not_take, take});
  }
  long long maximumStrength(vector<int> &nums, int k) {
    // options: not take, take and make new, take and continue
    int n = nums.size();
    dp.resize(n + 1,
              vector<vector<long long>>(k + 1, vector<long long>(2, -1)));
    return solve(0, k, true, nums);
  }
};

// Approach 2: bottom up
