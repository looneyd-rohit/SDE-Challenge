// Leetcode 1306

// [IMP] Approach: bfs + forming different type of graph
class Solution {
public:
  bool canReach(vector<int> &arr, int start) {
    int n = arr.size();
    // problem can be solved better if we represent int the form of a graph
    // as traversal in more than one direction can happen any time
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < n; i++) {
      if (i + arr[i] < n)
        adj[i].push_back(i + arr[i]);
      if (i - arr[i] >= 0a)
        adj[i].push_back(i - arr[i]);
    }
    queue<int> q;
    q.push(start);
    vector<bool> visited(n, false);
    visited[start] = true;
    while (!q.empty()) {
      auto node = q.front();
      q.pop();
      if (arr[node] == 0)
        return true;
      // visit neighbours
      for (auto &e : adj[node]) {
        if (!visited[e]) {
          visited[e] = true;
          q.push(e);
        }
      }
    }
    return false;
  }
};

// [IMP] Approach: dfs + forming different type of graph
class Solution {
public:
  bool dfs(int node, unordered_map<int, list<int>> &adj, vector<bool> &visited,
           vector<int> &arr) {
    visited[node] = true;
    if (arr[node] == 0)
      return true;
    for (auto &next : adj[node]) {
      if (!visited[next]) {
        if (dfs(next, adj, visited, arr))
          return true;
      }
    }
    return false;
  }
  bool canReach(vector<int> &arr, int start) {
    int n = arr.size();
    // problem can be solved better if we represent int the form of a graph
    // as traversal in more than one direction can happen any time
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < n; i++) {
      if (i + arr[i] < n)
        adj[i].push_back(i + arr[i]);
      if (i - arr[i] >= 0)
        adj[i].push_back(i - arr[i]);
    }
    vector<bool> visited(n, false);
    return dfs(start, adj, visited, arr);
  }
};