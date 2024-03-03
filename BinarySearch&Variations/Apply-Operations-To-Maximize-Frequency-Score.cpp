// Leetcode 2968
// Approach: binary search on answer + prefix sum
class Solution {
public:
  bool isPossible(vector<int> &nums, vector<long long> &pref_sum, int mid_score,
                  long long k) {
    int n = nums.size();
    int j = mid_score - 1;
    for (int i = 0; i < n && j < n; i++, j++) {
      int mid_val_ind = i + ((j - i) >> 1);
      long long ops_left =
          (pref_sum[mid_val_ind] - ((i > 0) ? pref_sum[i - 1] : 0));
      ops_left -= (nums[mid_val_ind] * 1LL * (mid_val_ind - i + 1));
      long long ops_right = pref_sum[j] - pref_sum[mid_val_ind];
      ops_right -= (nums[mid_val_ind] * 1LL * (j - mid_val_ind));
      long long ops = abs(ops_left) + abs(ops_right);
      if (ops <= k)
        return true;
    }
    return false;
  }
  int calculateMaxFrequency(vector<int> &nums) {
    int max_freq = 0;
    unordered_map<int, int> freq;
    for (auto &e : nums) {
      freq[e]++;
      max_freq = max(max_freq, freq[e]);
    }
    return max_freq;
  }
  int maxFrequencyScore(vector<int> &nums, long long k) {
    int n = nums.size();
    sort(begin(nums), end(nums));
    vector<long long> pref_sum(n, nums[0]);
    for (int i = 1; i < n; i++)
      pref_sum[i] = pref_sum[i - 1] + nums[i];
    // binary search on answer --> score
    int low_score = 1, high_score = n;
    int max_freq = calculateMaxFrequency(nums);
    while (low_score <= high_score) {
      int mid_score = low_score + ((high_score - low_score) >> 1);
      if (isPossible(nums, pref_sum, mid_score, k)) {
        max_freq = max(max_freq, mid_score);
        low_score = mid_score + 1;
      } else {
        high_score = mid_score - 1;
      }
    }
    return max_freq;
  }
};