// Leetcode 238

// Approach 1: using division operator
class Solution {
public:
  vector<int> productExceptSelf(vector<int> &nums) {
    int n = nums.size();
    long long total_pdt = 1;
    int z = 0;
    for (int i = 0; i < n; i++) {
      if (nums[i] == 0) {
        z++;
      } else {
        total_pdt *= nums[i];
      }
    }
    vector<int> ans(n, 0);
    if (z == 0) {
      for (int i = 0; i < n; i++) {
        ans[i] = total_pdt / nums[i];
      }
    } else if (z == 1) {
      for (int i = 0; i < n; i++) {
        if (nums[i] == 0) {
          ans[i] = total_pdt;
          break;
        }
      }
    }
    return ans;
  }
};

// Approach 2: without using division operator, but extra space O(N)
class Solution {
public:
  vector<int> productExceptSelf(vector<int> &nums) {
    int n = nums.size();
    int left_pdt = 1, right_pdt = 1;
    vector<int> left(n, 1), right(n, 1);
    for (int i = 1; i < n; i++)
      left[i] = left[i - 1] * nums[i - 1];
    for (int i = n - 2; i >= 0; i--)
      right[i] = right[i + 1] * nums[i + 1];
    vector<int> ans;
    for (int i = 0; i < n; i++) {
      ans.push_back(left[i] * right[i]);
    }
    return ans;
  }
};

// Approach 3: without division, without extra space
class Solution {
public:
  vector<int> productExceptSelf(vector<int> &nums) {
    int n = nums.size();
    int left_pdt = 1, right_pdt = 1;
    vector<int> ans(n, 1);
    for (int i = 1; i < n; i++)
      ans[i] = ans[i - 1] * nums[i - 1];
    for (int i = n - 2; i >= 0; i--) {
      right_pdt = right_pdt * nums[i + 1];
      ans[i] = ans[i] * right_pdt;
    }
    return ans;
  }
};