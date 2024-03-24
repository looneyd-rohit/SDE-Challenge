// https://www.codechef.com/problems/TREEDISTSET

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ull unsigned long long
#define ll long long
#define REP(i, n) for (int(i) = 0; (i) < (n); (i)++)
#define nsync                                                                  \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);                                                               \
  cout.tie(NULL);

// constant
const int M = (int)(1e9 + 7);
const int s = 1e5 + 1;
const int INF = 3e18L + 5;
const int INF64 = 1e18;
const int NINF = 1e18 * (-1);

void fun() { cout << "MF World!!!" << endl; }

int max_len, farthest_node;

void dfsFarthestNode(int node, int parent, int len,
                     unordered_map<int, vector<int>> &adj) {
  if (len > max_len) {
    max_len = len;
    farthest_node = node;
  }
  for (auto &next : adj[node]) {
    if (next != parent) {
      dfsFarthestNode(next, node, len + 1, adj);
    }
  }
}

vector<int> max_path;
int dfsMaxPathLength(int node, int parent, unordered_map<int, vector<int>> &adj,
                     vector<int> &path) {
  path.push_back(node);
  if (path.size() > max_path.size()) {
    max_path = path;
  }
  int maxi = 0;
  for (auto &next : adj[node]) {
    if (next != parent) {
      maxi = max(maxi, 1 + dfsMaxPathLength(next, node, adj, path));
    }
  }
  path.pop_back();
  return maxi;
}

int32_t main() {
  nsync;
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("error.txt", "w", stderr);
#endif
  // Tree Distance Set
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    unordered_map<int, vector<int>> adj;
    int u, v;
    REP(i, n - 1) {
      cin >> u >> v;
      adj[u - 1].push_back(v - 1);
      adj[v - 1].push_back(u - 1);
    }

    // do 2 dfs to get the length of the diameter
    // of the tree

    // get the farthest point from any point
    max_len = 0, farthest_node = 0;
    dfsFarthestNode(0, -1, 0, adj);

    // get the diameter as well as the path
    vector<int> path;
    max_path.clear();
    int diameter = dfsMaxPathLength(farthest_node, -1, adj, path);

    // now color the nodes
    int diameter_nodes = diameter + 1;
    int remaining = n - diameter_nodes;
    vector<char> colors(n, '$');
    for (int i = 0; i < diameter_nodes / 2; i++)
      colors[max_path[i]] = 'R';
    for (int i = diameter_nodes / 2; i < diameter_nodes; i++)
      colors[max_path[i]] = 'B';
    int red_cnt = diameter_nodes / 2;
    int blue_cnt = diameter_nodes - red_cnt;
    for (int i = 0; i < n; i++) {
      if (colors[i] == '$') {
        if (red_cnt > blue_cnt) {
          colors[i] = 'B';
          blue_cnt++;
        } else {
          colors[i] = 'R';
          red_cnt++;
        }
      }
    }
    // output the result
    for (auto &e : colors)
      cout << e;
    cout << endl;
  }
  return 0;
}
