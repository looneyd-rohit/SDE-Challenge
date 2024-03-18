// Leetcode 1696

// Approach 1: top down gives TLE, but bottom up with multiset works
class Solution {
public:
  long long dp[100001];
  long long solve(int index, int k, int n, vector<int> &nums) {
    if (index >= n - 1)
      return nums[n - 1];

    if (dp[index] != -1)
      return dp[index];

    long long score = -1e18;
    for (int i = index + 1; i <= min(n - 1, index + k); i++) {
      score = max(score, nums[index] + solve(i, k, n, nums));
    }
    return dp[index] = score;
  }
  int maxResult(vector<int> &nums, int k) {
    int n = nums.size();
    // memset(dp, -1, sizeof(dp));
    // return solve(0, k, n, nums);

    // bottom up: with set optimization
    multiset<int, greater<int>> mst;
    mst.insert(nums.front());
    dp[0] = nums.front();
    if (n == 1)
      return dp[0];
    for (int index = 1; index < n; index++) {
      dp[index] = nums[index] + *mst.begin();
      if (index - k >= 0)
        mst.erase(mst.find(dp[index - k]));
      mst.insert(dp[index]);
    }
    return dp[n - 1];
  }
};

// Approach 2: bottom up optimization using deque
class Solution {
public:
  long long dp[100001];
  long long solve(int index, int k, int n, vector<int> &nums) {
    if (index >= n - 1)
      return nums[n - 1];

    if (dp[index] != -1)
      return dp[index];

    long long score = -1e18;
    for (int i = index + 1; i <= min(n - 1, index + k); i++) {
      score = max(score, nums[index] + solve(i, k, n, nums));
    }
    return dp[index] = score;
  }
  int maxResult(vector<int> &nums, int k) {
    int n = nums.size();
    // memset(dp, -1, sizeof(dp));
    // return solve(0, k, n, nums);

    // bottom up: with set optimization
    memset(dp, 0, sizeof(dp));
    deque<pair<int, int>> dq;
    dp[0] = nums.front();
    dq.push_back({dp[0], 0});
    if (n == 1)
      return dp[0];
    for (int index = 1; index < n; index++) {
      dp[index] = nums[index] + (dq.empty() ? 0 : dq.front().first);
      if (index - k >= 0) {
        if (dq.front().second == index - k) {
          // removing out of bounds score from dq
          dq.pop_front();
        }
      }
      // updating the dq
      while (!dq.empty() && dq.back().first < dp[index])
        dq.pop_back();
      dq.push_back({dp[index], index});
    }
    return dp[n - 1];
  }
};