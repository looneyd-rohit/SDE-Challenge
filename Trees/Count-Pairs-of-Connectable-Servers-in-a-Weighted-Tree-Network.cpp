// Leetcode 3067

class Solution {
public:
  int count(int node, int signalSpeed,
            unordered_map<int, list<pair<int, int>>> &adj) {
    vector<int> possibles;
    // O(N) -> visits all of the nodes
    for (auto &next : adj[node]) { // no of next nodes = t (branching)
      int p = dfs(next.first, node, next.second, signalSpeed, adj);
      possibles.push_back(p);
    }
    int sum = 0;
    for (int i = 0; i < possibles.size();
         i++) { // O(t*t) t-> no of branches of each node
      for (int j = i + 1; j < possibles.size(); j++) {
        sum += possibles[i] * possibles[j];
      }
    }
    return sum;
  }
  int dfs(int node, int parent, int sum, int signalSpeed,
          unordered_map<int, list<pair<int, int>>> &adj) {
    int ans = (sum % signalSpeed == 0);
    for (auto &next : adj[node]) {
      if (next.first != parent) {
        ans += dfs(next.first, node, sum + next.second, signalSpeed, adj);
      }
    }
    return ans;
  }
  vector<int> countPairsOfConnectableServers(vector<vector<int>> &edges,
                                             int signalSpeed) {
    int e = edges.size();
    unordered_map<int, list<pair<int, int>>> adj;
    for (auto &edge : edges) {
      int u = edge[0], v = edge[1], wt = edge[2];
      adj[u].push_back({v, wt});
      adj[v].push_back({u, wt});
    }
    int n = e + 1;
    vector<int> ans(n, 0);
    for (int i = 0; i < n; i++) {
      ans[i] = count(i, signalSpeed, adj);
    }
    return ans;
  }
};