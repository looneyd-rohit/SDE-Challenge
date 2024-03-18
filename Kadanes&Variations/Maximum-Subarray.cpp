// Leetcode 53

// Approach: kadane's algorithm
class Solution {
public:
  int maxSubArray(vector<int> &nums) {
    // kadane's problem
    int n = nums.size();
    int maxOverall = -1e9, maxTillNow = -1e9;
    for (int i = 0; i < n; i++) {
      maxTillNow = max(nums[i], maxTillNow + nums[i]);

      maxOverall = max(maxOverall, maxTillNow);

      // if(maxTillNow < 0) maxTillNow = 0;
    }
    return maxOverall;
  }
};