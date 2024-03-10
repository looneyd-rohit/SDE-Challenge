// Leetcode 300

class Solution {
public:
  int lengthOfLIS(vector<int> &nums) {
    int n = nums.size();
    vector<int> lis;
    for (int i = 0; i < n; i++) {
      // find the equal or just greater element in existing lis
      auto it = lower_bound(begin(lis), end(lis), nums[i]);
      if (it == end(lis)) {
        lis.push_back(nums[i]);
      } else {
        *it = nums[i];
      }
    }
    return lis.size();
  }
};