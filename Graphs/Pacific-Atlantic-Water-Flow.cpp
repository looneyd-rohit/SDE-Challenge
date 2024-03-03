// Leetcode 417
// Approach: bfs from boundary
class Solution {
public:
  vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
  bool checkBoundary(int i, int j, int m, int n) {
    if (i < 0 || j < 0 || i >= m || j >= n)
      return false;
    return true;
  }
  void bfs(int m, int n, vector<vector<int>> &heights, queue<pair<int, int>> &q,
           set<pair<int, int>> &visited) {
    while (!q.empty()) {
      auto f = q.front();
      q.pop();
      int x = f.first, y = f.second;
      if (visited.count(f))
        continue;
      visited.insert(f);
      // visit neighbours
      for (auto &dir : directions) {
        int dx = dir.first, dy = dir.second;
        int new_x = x + dx, new_y = y + dy;
        if (checkBoundary(new_x, new_y, m, n)) {
          if (heights[new_x][new_y] >= heights[x][y]) {
            // water can travel
            q.push({new_x, new_y});
          }
        }
      }
    }
  }
  vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights) {
    int m = heights.size(), n = heights[0].size();
    // store all the cells which can reach pacific ocean
    // as well as all the cells which can reach atlantic ocean
    // take intersection of both
    set<pair<int, int>> pacific_coord, atlantic_coord;
    queue<pair<int, int>> pacific_q, atlantic_q;
    for (int i = 0; i < m; i++) {
      // pacific ocean
      pacific_q.push({i, 0});

      // atlantic ocean
      atlantic_q.push({i, n - 1});
    }
    for (int j = 0; j < n; j++) {
      // pacific ocean
      pacific_q.push({0, j});

      // atlantic ocean
      atlantic_q.push({m - 1, j});
    }
    // pacific bfs
    bfs(m, n, heights, pacific_q, pacific_coord);
    // atlantic bfs
    bfs(m, n, heights, atlantic_q, atlantic_coord);
    vector<vector<int>> ans;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        pair<int, int> p = make_pair(i, j);
        if (pacific_coord.count(p) && atlantic_coord.count(p)) {
          int x = p.first, y = p.second;
          vector<int> temp;
          temp.push_back(x);
          temp.push_back(y);
          ans.push_back(temp);
        }
      }
    }
    return ans;
  }
};