// Leetcode 200

// Approach: dfs or bfs both works
class Solution {
public:
  void dfs(int i, int j, int m, int n, vector<vector<char>> &grid) {
    if (i < 0 || j < 0 || i >= m || j >= n)
      return; // out of bounds
    if (grid[i][j] == '0')
      return; // water
    grid[i][j] = '0';
    dfs(i + 1, j, m, n, grid);
    dfs(i - 1, j, m, n, grid);
    dfs(i, j + 1, m, n, grid);
    dfs(i, j - 1, m, n, grid);
  }
  vector<pair<int, int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
  bool checkBounds(int x, int y, int m, int n) {
    if (x < 0 || y < 0 || x >= m || y >= n)
      return false;
    return true;
  }
  void bfs(int i, int j, int m, int n, vector<vector<char>> &grid) {
    queue<pair<int, int>> q;
    q.push({i, j});
    while (!q.empty()) {
      auto f = q.front();
      q.pop();
      int x = f.first, y = f.second;
      if (grid[x][y] == '0')
        continue;
      grid[x][y] = '0';
      // visit neighbours
      for (auto &dir : directions) {
        int dx = dir.first, dy = dir.second;
        int new_x = x + dx, new_y = y + dy;
        if (checkBounds(new_x, new_y, m, n)) {
          if (grid[new_x][new_y] == '1') {
            q.push({new_x, new_y});
          }
        }
      }
    }
  }
  int numIslands(vector<vector<char>> &grid) {
    int m = grid.size(), n = grid[0].size();
    int count = 0;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == '1') {
          count++;
          bfs(i, j, m, n, grid);
        }
      }
    }
    return count;
  }
};