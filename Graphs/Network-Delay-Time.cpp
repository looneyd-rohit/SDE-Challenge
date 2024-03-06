// Leetcode 743

// Approach 1: minheap + dijkstra
class Solution {
public:
  int networkDelayTime(vector<vector<int>> &times, int n, int k) {
    int t = times.size();
    unordered_map<int, list<pair<int, int>>> adj;
    for (auto &time : times) {
      int u = time[0], v = time[1], s = time[2];
      adj[u].push_back({v, s});
    }
    // <time, node>
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;
    pq.push({0, k});
    vector<int> distances(n, INT_MAX);
    distances[k - 1] = 0;
    while (!pq.empty()) {
      auto f = pq.top();
      pq.pop();
      int time = f.first, node = f.second;
      // visit neighbours
      for (auto &next : adj[node]) {
        if (distances[next.first - 1] > time + next.second) {
          distances[next.first - 1] = time + next.second;
          pq.push({distances[next.first - 1], next.first});
        }
      }
    }
    int maxi = 0;
    for (auto &e : distances)
      maxi = max(maxi, e);
    return maxi == INT_MAX ? -1 : maxi;
  }
};

// Approach 2: normal queue also works
class Solution {
public:
  int networkDelayTime(vector<vector<int>> &times, int n, int k) {
    int t = times.size();
    unordered_map<int, list<pair<int, int>>> adj;
    for (auto &time : times) {
      int u = time[0], v = time[1], s = time[2];
      adj[u].push_back({v, s});
    }
    // <time, node>
    // priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,
    // int>>> pq;
    queue<pair<int, int>> q;
    q.push({0, k});
    vector<int> distances(n, INT_MAX);
    distances[k - 1] = 0;
    while (!q.empty()) {
      auto f = q.front();
      q.pop();
      int time = f.first, node = f.second;
      // visit neighbours
      for (auto &next : adj[node]) {
        if (distances[next.first - 1] > time + next.second) {
          distances[next.first - 1] = time + next.second;
          q.push({distances[next.first - 1], next.first});
        }
      }
    }
    int maxi = 0;
    for (auto &e : distances)
      maxi = max(maxi, e);
    return maxi == INT_MAX ? -1 : maxi;
  }
};