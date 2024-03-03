// Leetcode 909
// [IMP]: MSBFS Pattern
class Solution {
public:
  int snakesAndLadders(vector<vector<int>> &board) {
    // seems like MSBFS should be applied
    int n = board.size();
    vector<int> vBoard;
    for (int i = n - 1; i >= 0; i--) {
      vector<int> temp = board[i];
      int diff = n - i;
      if (!(diff & 1)) {
        // right to left
        // reverse it
        reverse(begin(temp), end(temp));
      }
      for (auto &e : temp)
        vBoard.push_back(e);
    }

    vector<bool> visited(n * n, false);
    queue<pair<int, int>> q;
    q.push({0, 0});
    visited[0] = true;
    while (!q.empty()) {
      auto f = q.front();
      q.pop();
      int node = f.first, dist = f.second;
      if (node == n * n - 1)
        return dist;
      // visit neighbours
      for (int move = 1; move <= 6; move++) {
        int next_node = min(node + move, n * n - 1);
        int val = vBoard[next_node];
        if (val == -1) {
          // no snake or ladder
          if (!visited[next_node]) {
            visited[next_node] = true;
            q.push({next_node, dist + 1});
          }
        } else {
          // presence of snake or ladder
          // go to the place pointed by the snake or ladder
          val--;
          next_node = val;
          if (!visited[next_node]) {
            visited[next_node] = true;
            q.push({next_node, dist + 1});
          }
        }
      }
    }
    return -1;
  }
};

// Approach: normal bfs (finding coordinate from value)
class Solution {
public:
  pair<int, int> findCoordinatesFromNumber(int val, int n) {
    int d = (val - 1) / n;
    int rem = (val - 1) % n;
    if (d & 1) {
      return {n - 1 - d, n - 1 - rem};
    } else {
      return {n - 1 - d, rem};
    }
  }
  int snakesAndLadders(vector<vector<int>> &board) {
    // seems like bfs
    int n = board.size();
    queue<pair<int, int>> q;
    q.push({1, 0});
    vector<int> visited(n * n + 1, false);
    while (!q.empty()) {
      auto f = q.front();
      q.pop();
      if (f.first == n * n)
        return f.second;
      if (visited[f.first])
        continue;
      visited[f.first] = true;
      // visit neighbours
      for (int next = f.first + 1; next <= min(f.first + 6, n * n); next++) {
        auto p = findCoordinatesFromNumber(next, n);
        int x = p.first, y = p.second;
        if (board[x][y] != -1) {
          // has snake or ladder
          int new_next = board[x][y];
          q.push({new_next, f.second + 1});
        } else {
          q.push({next, f.second + 1});
        }
      }
    }
    return -1;
  }
};