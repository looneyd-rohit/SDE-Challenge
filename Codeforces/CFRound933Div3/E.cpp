// https://codeforces.com/contest/1941/problem/E

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

int32_t main() {
  nsync;
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("error.txt", "w", stderr);
#endif
  // Rudolf and k Bridges
  int t;
  cin >> t;
  while (t--) {
    int n, m, k, d;
    cin >> n >> m >> k >> d;
    vector<vector<int>> grid(n, vector<int>(m));
    REP(i, n) REP(j, m) cin >> grid[i][j];
    vector<int> k_arr;
    REP(i, n) {
      vector<int> dp(m, -1);
      dp[0] = 1;
      multiset<int> mst;
      mst.insert(1);
      for (int j = 1; j < m - 1; j++) {
        dp[j] = *mst.begin() + grid[i][j] + 1;
        if (j - d - 1 >= 0)
          mst.erase(mst.find((dp[j - d - 1])));
        mst.insert(dp[j]);
      }
      dp[m - 1] = *mst.begin() + 1;
      k_arr.push_back(dp[m - 1]);
    }
    int sum = 0;
    REP(i, k) sum += k_arr[i];
    int mini = sum;
    for (int i = k; i < n; i++)
      mini = min(mini, sum += k_arr[i] - k_arr[i - k]);
    cout << mini << endl;
  }
  return 0;
}
