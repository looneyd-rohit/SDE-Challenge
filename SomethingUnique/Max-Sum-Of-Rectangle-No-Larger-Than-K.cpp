// Leetcode 363

// [IMP] Approach: khandani 2D rectangle optimized approach based on prefix sum
// (c * c * r) wala technique
class Solution {
public:
  int maxSumSubmatrix(vector<vector<int>> &matrix, int k) {
    int m = matrix.size(), n = matrix[0].size();
    // find the prefix sum and apply rectangle logic -> (c * c * r)
    // similar to kadane's in 2D rectangle, count of submatrices with target sum
    // etc
    for (int i = 0; i < m; i++) {
      for (int j = 1; j < n; j++) {
        matrix[i][j] += matrix[i][j - 1];
      }
    }
    int maxi = -1e9;
    for (int col = 0; col < n; col++) {
      for (int j = col; j < n; j++) {
        map<int, bool> hash;
        hash[0] = true;
        int sum = 0;
        for (int i = 0; i < m; i++) {
          sum += matrix[i][j] - (col > 0 ? matrix[i][col - 1] : 0);
          int req = sum - k;
          auto it = hash.lower_bound(req);
          if (it != hash.end()) {
            maxi = max(maxi, sum - it->first);
          }

          hash[sum] = true;
        }
      }
    }
    return maxi;
  }
};