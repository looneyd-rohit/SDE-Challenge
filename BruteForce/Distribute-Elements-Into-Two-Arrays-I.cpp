// Leetcode 3069

class Solution {
public:
  vector<int> resultArray(vector<int> &nums) {
    int n = nums.size();
    vector<int> left, right;
    left.push_back(nums[0]);
    right.push_back(nums[1]);
    for (int i = 2; i < n; i++) {
      if (left.back() > right.back()) {
        left.push_back(nums[i]);
      } else {
        right.push_back(nums[i]);
      }
    }
    vector<int> result;
    for (auto &e : left)
      result.push_back(e);
    for (auto &e : right)
      result.push_back(e);
    return result;
  }
};