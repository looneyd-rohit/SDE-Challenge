// Leetcode 713

// Approach: subarray sliding window with count pattern
class Solution {
public:
  long long countOfSubArrayWithProductUptoK(vector<int> &nums, long long k) {
    int n = nums.size();
    long long pdt = 1, count = 0;
    int i = 0, j = 0;
    while (j < n) {
      pdt *= nums[j];
      if (pdt <= k) {
        count += (j - i + 1);
        j++;
      } else {
        while (pdt > k && i <= j) {
          pdt /= nums[i];
          i++;
        }
        count += (j - i + 1);
        j++;
      }
    }
    return count;
  }
  int numSubarrayProductLessThanK(vector<int> &nums, int k) {
    return countOfSubArrayWithProductUptoK(nums, k - 1);
  }
};