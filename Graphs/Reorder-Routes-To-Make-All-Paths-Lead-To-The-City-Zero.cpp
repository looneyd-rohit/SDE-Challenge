// Leetcode 1466

// Approach 1: using bfs
class Solution {
public:
  int minReorder(int n, vector<vector<int>> &connections) {
    unordered_map<int, list<pair<int, bool>>> adj;
    for (auto &connection : connections) {
      int u = connection[0], v = connection[1];
      adj[u].push_back({v, true});
      adj[v].push_back({u, false});
    }
    vector<bool> visited(n, false);
    queue<int> q;
    q.push(0);
    visited[0] = true;
    int cnt = 0;
    while (!q.empty()) {
      auto node = q.front();
      q.pop();

      // visit neighbours
      for (auto &next : adj[node]) {
        if (visited[next.first])
          continue;
        if (next.second == true) {
          // original edge points outward from 0
          // flip required
          cnt++;
        } else {
          // original edge points inward to zero
          // flip not required
        }
        visited[next.first] = true;
        q.push(next.first);
      }
    }
    return cnt;
  }
};

// Approach 2: using dfs
class Solution {
public:
  int cnt = 0;
  void dfs(int node, unordered_map<int, list<pair<int, bool>>> &adj,
           vector<bool> &visited) {
    visited[node] = true;
    for (auto &next : adj[node]) {
      if (!visited[next.first]) {
        if (next.second == false) {
          // original edge points inward to 0
          // flip not required
        } else {
          // original edge points outward from 0
          // flip required
          cnt++;
        }
        dfs(next.first, adj, visited);
      }
    }
  }
  int minReorder(int n, vector<vector<int>> &connections) {
    unordered_map<int, list<pair<int, bool>>> adj;
    for (auto &connection : connections) {
      int u = connection[0], v = connection[1];
      adj[u].push_back({v, true});
      adj[v].push_back({u, false});
    }
    vector<bool> visited(n, false);
    dfs(0, adj, visited);
    return cnt;
  }
};