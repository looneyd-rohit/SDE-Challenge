// Leetcode 2709

class DSU {
public:
  vector<int> parent;
  vector<int> rank;
  DSU(int n = 1) {
    parent.resize(n + 1, 0);
    rank.resize(n + 1, 0);
    for (int i = 0; i <= n; i++) {
      parent[i] = i;
      rank[i] = 1;
    }
  }
  int findParent(int u) {
    if (u == parent[u])
      return u;
    // path compression
    return parent[u] = findParent(parent[u]);
  }
  void unionByRank(int u, int v) {
    u = findParent(u);
    v = findParent(v);
    if (u == v)
      return;
    if (rank[u] == rank[v]) {
      parent[v] = u;
      rank[u]++;
    } else if (rank[u] < rank[v]) {
      parent[u] = v;
    } else {
      parent[v] = u;
    }
  }
};
class Solution {
public:
  const int N = 1e5;
  vector<bool> sieve;
  vector<int> lprimes;
  void generateSieve() {
    sieve.resize(N + 1, true);
    lprimes.resize(N + 1, -1);
    sieve[0] = sieve[1] = false;
    for (int i = 2; i <= N; i++) {
      if (sieve[i]) {
        lprimes[i] = i;
        for (int j = 2 * i; j <= N; j += i) {
          sieve[j] = false;
          if (lprimes[j] == -1)
            lprimes[j] = i;
        }
      }
    }
  }
  void generateUniqueDivisors(int ind, int n, map<int, vector<int>> &factors) {
    while (n > 1) {
      int lowprime = lprimes[n];
      while (n % lowprime == 0) {
        n /= lowprime;
      }
      factors[lowprime].push_back(ind);
    }
  }
  bool canTraverseAllPairs(vector<int> &nums) {
    int n = nums.size();
    generateSieve();
    // optimized approach: sieve(prime factors) + dsu
    map<int, vector<int>> factors;
    for (int i = 0; i < n; i++) {
      int num = nums[i];
      generateUniqueDivisors(i, num, factors);
    }
    DSU *dsu = new DSU(n);
    for (auto &e : factors) {
      int factor = e.first;
      if (e.second.size() == 0)
        continue;
      int el = e.second[0];
      for (int j = 0; j < e.second.size(); j++) {
        dsu->unionByRank(el, e.second[j]);
      }
    }
    int parent = dsu->findParent(0);
    for (int i = 1; i < n; i++)
      if (parent != dsu->findParent(i))
        return false;
    return true;
  }
};