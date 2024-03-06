// Leetcode 3068

// Approach 1: using dp (take or not take)
// traversing all possibilities of doing xor or not doing
// xor on all numbers of num
class Solution {
public:
  long long dp[(int)2e4 + 1][2];
  long long solve(int index, bool is_xor, int k, int n, vector<int> &nums) {
    // base case
    if (index == n) {
      if (is_xor) { // some parent has been xor_ed but child xor remaining
                    // xor should be pairs if not then is_xor will be true
        return -1e9;
      }
      return 0;
    }

    // dp check
    if (dp[index][is_xor] != -1)
      return dp[index][is_xor];

    // doing xor
    long long do_xor =
        (nums[index] ^ k) + solve(index + 1, !is_xor, k, n, nums);
    // not doing xor
    long long not_do_xor = nums[index] + solve(index + 1, is_xor, k, n, nums);
    return dp[index][is_xor] = max({do_xor, not_do_xor});
  }
  long long maximumValueSum(vector<int> &nums, int k,
                            vector<vector<int>> &edges) {
    int n = nums.size();
    memset(dp, -1, sizeof(dp));
    return solve(0, 0, k, n, nums);
  }
};

// Approach 2: using xor property + property of trees
// propagating xor between two numbers which wants
// to maximize
// for even count -> all numbers can be maximized
// for odd count -> one sacrifice: either do one more
// xor taking up some decrease or do one less xor
class Solution {
public:
  long long maximumValueSum(vector<int> &nums, int k,
                            vector<vector<int>> &edges) {
    int n = nums.size();
    int cnt = 0;
    long long sum = 0, minimum_diff_after_xor = INT_MAX;
    // if count is even -> all can be increased
    // if count is odd -> all may or may not be increased
    // if all are increased one needs to be decreased -> so decrease should be
    // minimum if all are not increased one needs to be sacrificed -> so
    // sacrifice should be minimum
    for (int i = 0; i < n; i++) {
      if ((nums[i] ^ k) > nums[i]) {
        cnt++;
        sum += nums[i] ^ k; // always taking the greatest possible
        minimum_diff_after_xor =
            min(minimum_diff_after_xor, 1LL * ((nums[i] ^ k) - nums[i]));
      } else {
        sum += nums[i]; // always taking the greatest possible
        minimum_diff_after_xor =
            min(minimum_diff_after_xor, 1LL * (nums[i] - (nums[i] ^ k)));
      }
    }
    if (cnt & 1)
      return (sum - minimum_diff_after_xor);
    return sum;
  }
};