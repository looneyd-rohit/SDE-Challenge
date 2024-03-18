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
    int pref = 1, suff = 1;
    int max_product = -1e9;
    for (int i = 0; i < n; i++) {
      if (pref == 0)
        pref = 1;
      if (suff == 0)
        suff = 1;
      pref = pref * nums[i];
      suff = suff * nums[n - i - 1];
      max_product = max({max_product, pref, suff});
    }
    return max_product;
  }
};

// Approach 2: