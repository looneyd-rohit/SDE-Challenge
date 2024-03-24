// Leetcode 2449

// [IMP] Approach: sorting + odd even handling differently
class Solution {
public:
  long long makeSimilar(vector<int> &nums, vector<int> &target) {
    // similar to problem where we need to convert A to B
    // by a[i] + 1 && a[j] - 1
    // we simply add up all the differences and return divided by 2
    // here, we need to separate into two groups as odd and even does
    // not change parity
    int n = nums.size();
    vector<vector<int>> nums_sep(2), target_sep(2);
    for (int i = 0; i < n; i++) {
      if (nums[i] & 1) {
        nums_sep[1].push_back(nums[i]);
      } else {
        nums_sep[0].push_back(nums[i]);
      }
      if (target[i] & 1) {
        target_sep[1].push_back(target[i]);
      } else {
        target_sep[0].push_back(target[i]);
      }
    }
    sort(begin(nums_sep[0]), end(nums_sep[0]));
    sort(begin(nums_sep[1]), end(nums_sep[1]));
    sort(begin(target_sep[0]), end(target_sep[0]));
    sort(begin(target_sep[1]), end(target_sep[1]));
    long long total = 0;
    // handle even numbers
    for (int i = 0; i < nums_sep[0].size(); i++) {
      total += abs(nums_sep[0][i] - target_sep[0][i]) / 2;
    }
    // handle odd numbers
    for (int i = 0; i < nums_sep[1].size(); i++) {
      total += abs(nums_sep[1][i] - target_sep[1][i]) / 2;
    }
    return (total /
            2); // since it accounted two times (increase as well decrease)
  }
};