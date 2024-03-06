// Leetcode 368

// Approach: DP + LIS variant
class Solution {
public:
  vector<int> largestDivisibleSubset(vector<int> &nums) {
    int n = nums.size();
    sort(begin(nums), end(nums));
    vector<int> dp(n, 1), parent(n, -1);
    int max_index = 0;
    for (int i = 1; i < n; i++) {
      for (int j = 0; j < i; j++) {
        if (nums[i] % nums[j] == 0) {
          if (dp[i] < dp[j] + 1) {
            dp[i] = dp[j] + 1;
            parent[i] = j; // marking previous elements
          }
        }
      }
      if (dp[i] > dp[max_index]) {
        max_index = i;
      }
    }
    vector<int> ans;
    ans.push_back(nums[max_index]);
    while (parent[max_index] != -1) {
      max_index = parent[max_index];
      ans.push_back(nums[max_index]);
    }
    return ans;
  }
};