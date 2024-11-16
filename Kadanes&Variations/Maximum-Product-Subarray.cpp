// Leetcode 152

// Approach 1: using some observations, prefix + suffix
class Solution {
public:
  int maxProduct(vector<int> &nums) {
    int n = nums.size();
    // 1. for even negatives entire product is the answer
    // 2. for odd negatives we check the prefix and suffix surrounding the
    // negative
    // 3. for zeros we start afresh
    long long pref = 1, suff = 1;
    long long max_product = LONG_MIN;
    for (int i = 0; i < n; i++) {
      if (pref == 0)
        pref = 1;
      if (suff == 0)
        suff = 1;
      if(pref*nums[i]>=INT_MIN && pref*nums[i]<=INT_MAX) pref = pref * nums[i];
      if(suff * nums[n - i - 1]>=INT_MIN && suff * nums[n - i - 1] <= INT_MAX) suff = suff * nums[n - i - 1];
      max_product = max({max_product, pref, suff});
    }
    return max_product;
  }
};