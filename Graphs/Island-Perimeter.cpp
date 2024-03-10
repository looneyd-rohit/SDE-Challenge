// Leetcode 463

class Solution {
public:
  int solve(int i, int j, int m, int n, vector<vector<int>> &grid) {
    if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == 0)
      return 1;
    if (grid[i][j] == -1)
      return 0; // already visited cells
    grid[i][j] = -1;
    int a = solve(i - 1, j, m, n, grid);
    int b = solve(i + 1, j, m, n, grid);
    int c = solve(i, j - 1, m, n, grid);
    int d = solve(i, j + 1, m, n, grid);
    return (a + b + c + d);
  }
  int islandPerimeter(vector<vector<int>> &grid) {
    int m = grid.size(), n = grid[0].size();

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == 1) {
          return solve(i, j, m, n, grid);
        }
      }
    }
    return 0;
  }
};