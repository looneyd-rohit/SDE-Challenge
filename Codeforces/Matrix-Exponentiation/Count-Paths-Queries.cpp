/*
Editorial
*/

#include <bits/stdc++.h>
using namespace std;
int n;
const int mod = 1e9 + 7;
struct Matrix {
  vector<vector<int>> a = vector<vector<int>>(n, vector<int>(n));
  Matrix operator*(const Matrix &other) {
    vector<vector<int>> product(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        for (int k = 0; k < n; ++k) {
          product[i][k] =
              (product[i][k] + (long long)a[i][j] * other.a[j][k]) % mod;
        }
      }
    }
    Matrix retu{product};
    return retu;
  }
};
int main() {
  int m, q;
  scanf("%d%d%d", &n, &m, &q);
  Matrix base;
  for (int i = 0; i < m; ++i) {
    int a, b;
    scanf("%d%d", &a, &b);
    base.a[a - 1][b - 1]++;
  }
  vector<Matrix> powers{base};
  for (int i = 1; i <= 30; ++i) {
    powers.push_back(powers.back() * powers.back());
  }
  while (q--) {
    int a, b, k;
    scanf("%d%d%d", &a, &b, &k);
    a--;
    b--;
    vector<int> dp(n);
    dp[a]++;
    for (int bit = 0; (1 << bit) <= k; ++bit) {
      if (k & (1 << bit)) {
        vector<int> new_dp(n);
        for (int i = 0; i < n; ++i) {
          for (int j = 0; j < n; ++j) {
            new_dp[j] =
                (new_dp[j] + (long long)dp[i] * powers[bit].a[i][j]) % mod;
          }
        }
        dp = new_dp;
      }
    }
    printf("%d\n", dp[b]);
  }
}

/*
My solution: (TLE) ??

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

// constants
const int M = (int)(1e9 + 7);
const int s = 1e5 + 1;
const int INF = 3e18L + 5;
const int INF64 = 1e18;
const int NINF = 1e18 * (-1);

void printArray(vector<int> &arr) {
  for (auto &e : arr)
    cout << e << " ";
  cout << endl;
  cout << "-----------" << endl;
}

auto multiplyMatrices(vector<vector<int>> &a, vector<vector<int>> &b) {
  int n = a.size();
  vector<vector<int>> ans(n, vector<int>(n, 0));
  REP(i, n) {
    REP(j, n) {
      REP(k, n) {
        ans[i][j] += (a[i][k] * b[k][j]) % M;
        ans[i][j] %= M;
        ans[i][j] += M;
        ans[i][j] %= M;
      }
    }
  }
  return ans;
}
auto multiplyRowByMatrix(vector<int> &res, vector<vector<int>> &mat) {
  int n = mat.size();
  vector<int> ans(n, 0);
  REP(i, n) {
    REP(j, n) {
      ans[i] += (res[j] * mat[j][i]) % M;
      ans[i] %= M;
      ans[i] += M;
      ans[i] %= M;
    }
  }
  return ans;
}

void precompute(vector<vector<int>> &adj, vector<vector<vector<int>>> &store) {
  store.push_back(adj);
  for (int i = 1; i <= 30; i++) {
    store.push_back(multiplyMatrices(store.back(), store.back()));
  }
}

int log2(int n) {
  int res = 0;
  int val = 1;
  while (val <= n) {
    res++;
    val *= 2;
  }
  return (res - 1);
}

auto compute(vector<vector<int>> &adjMat, int s, int t, int k,
             vector<vector<vector<int>>> &store) {
  int n = adjMat.size();
  vector<int> res(n, 0);
  res[s - 1] = 1;
  // cout << p << ": ";
  int i = 0;
  while (k) {
    if (k & 1) {
      res = multiplyRowByMatrix(res, store[i]);
    }
    i++;
    k = k >> 1;
  }
  return res[t - 1];
}

int32_t main() {
  // H. String Mood Updates
  nsync;
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("error.txt", "w", stderr);
#endif
  // sieve();
  // int t;
  // cin >> t;
  // while (t--) {

  // }

  int n, m, q;
  cin >> n >> m >> q;
  vector<vector<int>> adjMat(n, vector<int>(n, 0));
  REP(i, m) {
    int u, v;
    cin >> u >> v;
    adjMat[u - 1][v - 1] = 1;
  }

  // precompute M ^ (1e9)
  vector<vector<vector<int>>> store;
  precompute(adjMat, store);
  // REP(l, 31) {
  //   REP(i, n) {
  //     REP(j, n) { cout << store[l][i][j] << " "; }
  //     cout << endl;
  //   }
  //   cout << "------------------" << endl;
  // }

  REP(i, q) {
    int s, t, k;
    cin >> s >> t >> k;
    // scanf("%lld%lld%lld", &s, &t, &k);
    cout << compute(adjMat, s, t, k, store) << endl;
  }

  return 0;
}

*/