// Leetcode 3086

// [IMP] Approach: detailed derivation to reducing the problem + sliding window
// + priority on operations
class Solution {
public:
  int countMaxConsecutiveOnes(vector<int> &nums) {
    int n = nums.size();
    int maxi = 0;
    for (int i = 0; i < n; i++) {
      if (nums[i] == 1) {
        int j = i;
        int cnt = 0;
        while (j < n && nums[j] == 1) {
          cnt++;
          maxi = max(maxi, cnt);
          j++;
        }
        i = j - 1;
      }
    }
    return maxi;
  }
  long long minimumMoves(vector<int> &nums, int k, int maxChanges) {
    int n = nums.size();
    // approach: count the minimum number of operations based on the idea
    // that to apply operation 1 we need 2 moves to get 1 point
    // and to apply operation 2 we need k moves to get 1 point, where
    // k is the distance of the 1 from that index

    // implementation:
    // we will always apply maxChanges, since even if we have
    // consecutive ones, that can be at max 0, 1, 2, or 3
    // after which if there are 4 or more consecutive ones they will
    // take more steps to come to the point and converge, hence taking
    // maxChanges and applying operation 2 is more suitable
    int max_consecutive_ones = min(3, countMaxConsecutiveOnes(nums));
    if (max_consecutive_ones >= k)
      return (k - 1);
    if (max_consecutive_ones + maxChanges >= k) {
      int r = k - max_consecutive_ones;
      return ((max_consecutive_ones > 0 ? max_consecutive_ones - 1 : 0) +
              2 * r);
    }

    // they don't satisfy since k is large so we need to check
    // based on distance
    k -= maxChanges;
    long long ops = 2 * maxChanges;

    vector<long long> ones;
    for (int i = 0; i < n; i++) {
      if (nums[i] == 1) {
        ones.push_back(i);
      }
    }
    vector<long long> prefix_sum = ones;
    for (int i = 1; i < ones.size(); i++) {
      prefix_sum[i] += prefix_sum[i - 1];
    }

    int low = 0, high = k - 1;
    long long min_ops_2 = LONG_LONG_MAX;
    while (high < ones.size()) {
      int optimal_mid = low + ((high - low) >> 1);
      long long left_ops =
          ones[optimal_mid] * (optimal_mid - low + 1) -
          (prefix_sum[optimal_mid] - (low > 0 ? prefix_sum[low - 1] : 0));
      long long right_ops = (prefix_sum[high] - prefix_sum[optimal_mid]) -
                            (ones[optimal_mid] * (high - optimal_mid));
      min_ops_2 = min(min_ops_2, left_ops + right_ops);
      low++;
      high++;
    }
    return (ops + min_ops_2);
  }
};