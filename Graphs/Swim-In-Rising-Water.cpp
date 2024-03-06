// Leetcode 778

// Approach: Greedy Approach to reach the destination --> dijkstra type but
// priority is on time
class Solution {
public:
  bool checkBounds(int x, int y, int m, int n) {
    if (x < 0 || y < 0 || x >= m || y >= n)
      return false;
    return true;
  }
  int swimInWater(vector<vector<int>> &grid) {
    int n = grid.size();
    vector<pair<int, int>> moves = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                   greater<tuple<int, int, int>>>
        pq;
    pq.push(tuple<int, int, int>(grid[0][0], 0, 0));
    grid[0][0] = -1;
    while (!pq.empty()) {
      auto top = pq.top();
      pq.pop();
      int time = get<0>(top), x = get<1>(top), y = get<2>(top);
      // cout<<"time: "<<time<<" x: "<<x<<" y: "<<y<<endl;
      if (x == n - 1 && y == n - 1)
        return time;
      for (auto &mm : moves) {
        int dx = mm.first, dy = mm.second;
        int new_x = x + dx, new_y = y + dy;
        if (checkBounds(new_x, new_y, n, n)) {
          if (grid[new_x][new_y] != -1) {
            pq.push(tuple<int, int, int>(max(time, grid[new_x][new_y]), new_x,
                                         new_y));
            grid[new_x][new_y] = -1;
          }
        }
      }
    }
    return -1;
  }
};

// Same approach but new code
class Solution {
public:
  vector<pair<int, int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
  bool checkBoundary(int x, int y, int m, int n) {
    if (x < 0 || y < 0 || x >= m || y >= n)
      return false;
    return true;
  }
  int swimInWater(vector<vector<int>> &grid) {
    int n = grid.size();
    vector<vector<int>> distances(n, vector<int>(n, INT_MAX));
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                   greater<tuple<int, int, int>>>
        pq; // <time, x, y>
    pq.push(tuple<int, int, int>(grid[0][0], 0, 0));
    distances[0][0] = grid[0][0];
    while (!pq.empty()) {
      auto f = pq.top();
      pq.pop();
      int time = get<0>(f), x = get<1>(f), y = get<2>(f);
      if (x == n - 1 && y == n - 1)
        return time;
      // visit neighbours
      for (auto &dir : directions) {
        int dx = dir.first, dy = dir.second;
        int new_x = x + dx, new_y = y + dy;
        if (checkBoundary(new_x, new_y, n, n)) {
          // can only go to (new_x, new_y) from (x, y) only when
          // height of the both the cells match by water
          int new_time = max(time, grid[new_x][new_y]);
          if (distances[new_x][new_y] > new_time) {
            distances[new_x][new_y] = new_time;
            pq.push(tuple<int, int, int>(new_time, new_x, new_y));
          }
        }
      }
    }
    return 0;
  }
};