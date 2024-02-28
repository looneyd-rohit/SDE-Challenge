// https://codeforces.com/contest/1927/problem/E

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

int32_t main() {
  nsync;
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("error.txt", "w", stderr);
#endif
  // sieve();
  int t;
  cin >> t;
  while (t--) {

    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    int low = 1, high = n;
    for (int i = 0; i < k; i++) {
      for (int j = i; j < n; j += k) {
        if (i & 1)
          arr[j] = low++;
        else
          arr[j] = high--;
      }
    }
    for (auto &e : arr)
      cout << e << " ";
    cout << endl;
  }
  return 0;
}
