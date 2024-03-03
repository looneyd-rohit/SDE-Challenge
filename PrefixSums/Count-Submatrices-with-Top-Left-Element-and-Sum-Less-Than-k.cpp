// Leetcode 3070

class Solution {
public:
  void computeRowWisePrefixSum(vector<vector<int>> &grid) {
    int m = grid.size(), n = grid[0].size();
    for (int i = 0; i < m; i++) {
      for (int j = 1; j < n; j++) {
        grid[i][j] += grid[i][j - 1];
      }
    }
  }
  void computeColumnWisePrefixSum(vector<vector<int>> &grid) {
    int m = grid.size(), n = grid[0].size();
    for (int j = 0; j < n; j++) {
      for (int i = 1; i < m; i++) {
        grid[i][j] += grid[i - 1][j];
      }
    }
  }
  int countSubmatrices(vector<vector<int>> &grid, int k) {
    int m = grid.size(), n = grid[0].size();
    // find row wise prefix sum
    computeRowWisePrefixSum(grid);
    // then find column wise prefix sum
    computeColumnWisePrefixSum(grid);
    int count = 0;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        int sum = grid[i][j];
        if (sum <= k) {
          count++;
        }
      }
    }
    return count;
  }
};