// Leetcode 462

// Approach 1: using sorting to find median
class Solution {
public:
  int minMoves2(vector<int> &nums) {
    int n = nums.size();
    sort(begin(nums), end(nums));
    int med = nums[n >> 1];
    int res = 0;
    for (auto &e : nums)
      res += abs(e - med);
    return res;
  }
};

// Approach 2: summing up of differences does not depend on median but the
// actual difference between them if we observer carefully
class Solution {
public:
  int minMoves2(vector<int> &nums) {
    int n = nums.size();
    sort(begin(nums), end(nums));
    int res = 0;
    for (int i = 0; i < n / 2; i++) {
      res += nums[n - 1 - i] - nums[i];
    }
    return res;
  }
};

// Approach 3: using quick select algorithm
class Solution {
public:
  int getPivotIndex(vector<int> &nums, int low, int high) {
    int pivot_element = nums[high];
    int pivot_ind = low;
    for (int i = low; i <= high; i++) {
      if (nums[i] < pivot_element) {
        swap(nums[i], nums[pivot_ind]);
        pivot_ind++;
      }
    }
    swap(nums[high], nums[pivot_ind]);
    return pivot_ind;
  }

  int getKthElement(vector<int> &nums, int k, int low, int high) {
    int n = nums.size();
    int ind = getPivotIndex(nums, low, high);
    if (ind == k)
      return nums[ind];
    else if (ind > k)
      return getKthElement(nums, k, low, ind - 1);
    else
      return getKthElement(nums, k, ind + 1, high);
    return -1;
  }
  int minMoves2(vector<int> &nums) {
    // using quick select
    int n = nums.size();
    int med = getKthElement(nums, n / 2, 0, n - 1);
    int res = 0;
    for (auto &e : nums)
      res += abs(e - med);
    return res;
  }
};