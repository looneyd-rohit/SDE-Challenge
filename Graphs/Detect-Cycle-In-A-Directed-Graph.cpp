// https://www.codingninjas.com/studio/problems/detect-cycle-in-a-directed-graph_1062626?leftPanelTabValue=PROBLEM

// Approach 1: dfs + visited + in recursion visited
#include <bits/stdc++.h>
using namespace std;

bool dfs(int node, unordered_map<int, list<int>> &adj, vector<bool> &visited,
         vector<bool> &in_recursion_visited) {
  visited[node] = true;
  in_recursion_visited[node] = true;
  for (auto &next : adj[node]) {
    if (!visited[next]) {
      if (dfs(next, adj, visited, in_recursion_visited)) {
        return true;
      }
    } else if (in_recursion_visited[next]) {
      return true;
    }
  }
  in_recursion_visited[node] = false;
  return false;
}
int detectCycleInDirectedGraph(int n, vector<pair<int, int>> &edges) {
  unordered_map<int, list<int>> adj;
  for (auto &edge : edges) {
    int u = edge.first, v = edge.second;
    adj[u].push_back(v);
  }
  vector<bool> visited(n + 1, false);
  vector<bool> in_recursion_visited(n + 1, false);
  for (int i = 1; i <= n; i++) {
    if (!visited[i]) {
      if (dfs(i, adj, visited, in_recursion_visited)) {
        return true;
      }
    }
  }
  return false;
}

// Approach 2: bfs + kahn's algorithm (topological sort)
int detectCycleInDirectedGraph(int n, vector<pair<int, int>> &edges) {
  unordered_map<int, list<int>> adj;
  vector<int> indegree(n + 1, 0);
  for (auto &edge : edges) {
    int u = edge.first, v = edge.second;
    adj[u].push_back(v);
    indegree[v]++;
  }
  queue<int> q;
  for (int i = 1; i <= n; i++)
    if (indegree[i] == 0)
      q.push(i);
  vector<int> order;
  while (!q.empty()) {
    auto node = q.front();
    q.pop();
    order.push_back(node);
    // visit neighbours
    for (auto &next : adj[node]) {
      indegree[next]--;
      if (indegree[next] == 0) {
        q.push(next);
      }
    }
  }
  return (order.size() != n);
}