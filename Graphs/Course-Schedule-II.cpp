// Leetcode 210

class Solution {
public:
  vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
    int p = prerequisites.size();
    unordered_map<int, list<int>> adj;
    vector<int> indegree(numCourses, 0);
    for (auto &pre : prerequisites) {
      int u = pre[0], v = pre[1];
      adj[v].push_back(u);
      indegree[u]++;
    }
    queue<int> q;
    for (int i = 0; i < numCourses; i++)
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
    return (order.size() == numCourses ? order : vector<int>());
  }
};