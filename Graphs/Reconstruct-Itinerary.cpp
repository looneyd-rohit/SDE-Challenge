// Leetcode 332

// Approach: using topological sort type approach
class Solution {
public:
  void dfs(string &node, int n, unordered_map<string, multiset<string>> &adj,
           vector<string> &itinerary) {
    if (itinerary.size() == n + 1) {
      // all tickets used up
      return;
    }

    // visit neighbours
    while (!adj[node].empty()) {
      // erase to avoid loops
      auto it = adj[node].begin();
      string city = *it;
      adj[node].erase(it);

      dfs(city, n, adj, itinerary);
    }
    itinerary.push_back(node);
    return;
  }
  vector<string> findItinerary(vector<vector<string>> &tickets) {
    int n = tickets.size();
    unordered_map<string, multiset<string>> adj;
    for (auto &ticket : tickets) {
      auto u = ticket[0], v = ticket[1];
      adj[u].insert(v);
    }
    vector<string> itinerary;
    string start = "JFK";
    dfs(start, n, adj, itinerary);
    reverse(begin(itinerary), end(itinerary));
    return itinerary;
  }
};