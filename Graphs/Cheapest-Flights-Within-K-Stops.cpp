// Leetcode 787

// Approach: minheap + dijkstra + more priority to stops
class Solution {
public:
  int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst,
                        int k) {
    int f = flights.size();
    unordered_map<int, list<pair<int, int>>> adj;
    for (auto &flight : flights) {
      int u = flight[0], v = flight[1], c = flight[2];
      adj[u].push_back({v, c});
    }
    k++; // since we include the destination as our final stop
    // <stops, cost, city>
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                   greater<tuple<int, int, int>>>
        pq;
    pq.push(tuple<int, int, int>(0, 0, src));
    // give more priority to stops rather than cost
    // as some path may get blocked because it is longer
    // but has lower cost
    vector<int> costs(n, INT_MAX);
    costs[src] = 0;
    while (!pq.empty()) {
      auto t = pq.top();
      pq.pop();
      int curr_k = get<0>(t), cost = get<1>(t), node = get<2>(t);
      if (curr_k >= k)
        continue;
      // visit neighbours
      for (auto &next : adj[node]) {
        if (costs[next.first] > cost + next.second) {
          costs[next.first] = cost + next.second;
          pq.push(
              tuple<int, int, int>(curr_k + 1, costs[next.first], next.first));
        }
      }
    }
    return costs[dst] == INT_MAX ? -1 : costs[dst];
  }
};