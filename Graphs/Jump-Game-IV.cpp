// Leetcode 1345

// Approach: bfs + modified adjacency list + remove from adjacency list concept
class Solution {
public:
  int minJumps(vector<int> &arr) {
    int n = arr.size();
    unordered_map<int, list<int>> value_to_index;
    for (int i = 0; i < n; i++) {
      value_to_index[arr[i]].push_back(i);
    }
    queue<pair<int, int>> q;
    q.push({0, 0});
    vector<bool> visited(n, false);
    visited[0] = true;
    while (!q.empty()) {
      auto f = q.front();
      q.pop();
      int step = f.first, ind = f.second;
      if (ind == n - 1)
        return step;
      // visit neighbours
      if (ind > 0 && visited[ind - 1] == false) {
        visited[ind - 1] = true;
        q.push({1 + step, ind - 1});
      }
      if (ind < n - 1 && visited[ind + 1] == false) {
        visited[ind + 1] = true;
        q.push({1 + step, ind + 1});
      }
      for (auto &next : value_to_index[arr[ind]]) {
        if (visited[next] == false && next != ind) {
          visited[next] = true;
          q.push({1 + step, next});
        }
      }
      // we don't need to remove from map for smaller lists
      // but for larger lists, the traversal is done multiple times
      // even if nothing is added to queue so TLE occurs
      value_to_index.erase(arr[ind]);
    }
    return INT_MAX;
  }
};