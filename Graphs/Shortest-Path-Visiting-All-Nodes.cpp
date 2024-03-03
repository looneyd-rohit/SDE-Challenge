// Leetcode 847
// Approach: bfs + bit masking
class Solution {
public:
  int shortestPathLength(vector<vector<int>> &graph) {
    int n = graph.size();
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < n; i++) {
      for (auto &e : graph[i]) {
        adj[i].push_back(e);
        adj[e].push_back(i);
      }
    }
    queue<tuple<int, int, int>> q; // <node, mask, steps>
    for (int i = 0; i < n; i++) {
      q.push(tuple<int, int, int>(i, (1 << i), 0));
    }
    vector<vector<bool>> visited(12, vector<bool>(4096, false));
    while (!q.empty()) {
      auto f = q.front();
      q.pop();
      int node = get<0>(f), mask = get<1>(f), steps = get<2>(f);
      if (mask == ((1 << n) - 1))
        return steps;
      if (visited[node][mask])
        continue;
      visited[node][mask] = true;
      // visit neighbours
      for (auto &next : adj[node]) {
        if (visited[next][mask | (1 << next)])
          continue;
        q.push(tuple<int, int, int>(next, mask | (1 << next), steps + 1));
      }
    }
    return -1;
  }
};