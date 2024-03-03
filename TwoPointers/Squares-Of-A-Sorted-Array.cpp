// Leetcode 977

class Solution {
public:
  vector<int> sortedSquares(vector<int> &nums) {
    int n = nums.size();
    vector<int> ans(n, 0);
    int i = 0, j = n - 1;
    int k = n - 1;
    while (i < j) {
      int numi = abs(nums[i]), numj = abs(nums[j]);
      if (numi >= numj) {
        ans[k] = numi * numi;
        k--;
        i++;
      } else {
        ans[k] = numj * numj;
        k--;
        j--;
      }
    }
    ans[k] = nums[i] * nums[i];
    k--;
    return ans;
  }
};