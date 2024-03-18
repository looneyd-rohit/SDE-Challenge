// Leetcode 2302

// [IMP] Approach: subarray with count pattern
class Solution {
public:
  long long countOfSubArrayWithScoreUptoK(vector<int> &nums, long long k) {
    int n = nums.size();
    long long sum = 0, multiplier = 0, count = 0;
    int i = 0, j = 0;
    while (j < n) {
      sum += nums[j];
      multiplier++;
      long long score = sum * multiplier;
      if (score <= k) {
        count += (j - i + 1);
        j++;
      } else {
        while (score > k && i <= j) {
          sum -= nums[i];
          multiplier--;
          score = sum * multiplier;
          i++;
        }
        count += (j - i + 1);
        j++;
      }
    }
    return count;
  }
  long long countSubarrays(vector<int> &nums, long long k) {
    return countOfSubArrayWithScoreUptoK(nums, k - 1);
  }
};