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
              vector<vector<long long>>(k + 1, vector<long long>(2, -1e18)));
    // return solve(0, k, true, nums);

    // bottom up:
    for (int i = 0; i <= n; i++)
      dp[i][0][0] = dp[i][0][1] = 0;
    for (int index = n - 1; index >= 0; index--) {
      for (long long kk = 1; kk <= k; kk++) {
        for (int empty = 0; empty <= 1; empty++) {
          long long not_take = -1e18;

          if (empty) { // if empty we can either take or skip
            not_take = dp[index + 1][kk][true]; // skip
          }

          // take and make new subarray
          // or
          // take and continue current subarray
          long long take = -1e18;

          if (kk % 2 == 1) {
            take = dp[index + 1][kk - 1][true] + nums[index] * kk;
            take = max(take, dp[index + 1][kk][false] + nums[index] * kk);
          } else {
            take = dp[index + 1][kk - 1][true] - nums[index] * kk;
            take = max(take, dp[index + 1][kk][false] - nums[index] * kk);
          }

          dp[index][kk][empty] = max({not_take, take});
        }
      }
    }
    return dp[0][k][true];
  }
};