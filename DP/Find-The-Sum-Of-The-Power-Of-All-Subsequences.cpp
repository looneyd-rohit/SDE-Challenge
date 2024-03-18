// Leetcode 3082

// Approach: take / not take dp with slight observation
class Solution {
public:
  const int M = 1e9 + 7;
  int binExp(long long a, int b) {
    long long res = 1;
    while (b) {
      if (b & 1) {
        res = (res * a) % M;
      }
      a = (a * a) % M;
      b >>= 1;
    }
    return res % M;
  }
  int dp[101][101][101];
  long long solve(int index, int k, int len, int n, vector<int> &nums) {
    // cout<<index<<", "<<k<<", "<<len<<endl;
    if (index >= n) {
      if (k == 0) {
        return binExp(2, n - len) % M;
      }
      return 0;
    }

    if (dp[index][k][len] != -1)
      return dp[index][k][len];

    // take
    long long take = 0;
    if (k - nums[index] >= 0) {
      take = solve(index + 1, k - nums[index], len + 1, n, nums) % M;
    }

    // not take
    long long not_take = solve(index + 1, k, len, n, nums) % M;

    return dp[index][k][len] = (take + not_take) % M;
  }
  int sumOfPower(vector<int> &nums, int k) {
    int n = nums.size();
    memset(dp, -1, sizeof(dp));
    return solve(0, k, 0, n, nums);
  }
};