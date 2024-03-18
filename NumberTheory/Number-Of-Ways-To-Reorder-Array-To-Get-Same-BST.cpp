// Leetcode 1569

// [IMP] Approach: maintaining relative ordering + pascals triangle
class Solution {
public:
  const int M = 1e9 + 7;
  vector<vector<int>> pascal;
  int nCr(int n, int r) { return pascal[n][r]; }
  int solve(vector<int> &nums) {
    int n = nums.size();
    if (n == 0)
      return 1;
    int root = nums[0];
    vector<int> smaller, larger;
    for (int i = 1; i < n; i++) {
      if (nums[i] < root) {
        smaller.push_back(nums[i]);
      } else {
        larger.push_back(nums[i]);
      }
    }

    int left = solve(smaller);
    int right = solve(larger);

    int count = nCr(n - 1, smaller.size());

    return ((count * 1LL * ((left * 1LL * right) % M)) % M);
  }
  int numOfWays(vector<int> &nums) {
    // we need to maintain the relative order of elements same w.r.t to the root
    // of the tree, for this, we need to find all the possible orderings of the
    // elements except the root; for this we will take nCr, the combination of
    // elements rather than the arrangements, since we need to follow a strict
    // relative ordering
    // also to find the nCr we will use pascal's triangle
    int n = nums.size();
    pascal.push_back({1});
    pascal.push_back({1, 1});
    for (int i = 2; i <= n; i++) {
      vector<int> temp(i + 1, 1);
      for (int j = 1; j < i; j++) {
        temp[j] = (pascal[i - 1][j] + pascal[i - 1][j - 1]) % M;
      }
      pascal.push_back(temp);
    }
    return (solve(nums) - 1 + M) % M;
    return 69;
  }
};