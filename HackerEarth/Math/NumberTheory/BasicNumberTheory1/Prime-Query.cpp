// https://www.hackerearth.com/practice/math/number-theory/basic-number-theory-1/practice-problems/algorithm/prime-query-bbe5751b/

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
  // Prime Query
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> zeros(n, 0);
    vector<int> ones(n, 0);
    for (int i = 0; i < n; i++) {
      int t;
      cin >> t;
      if (t == 0)
        zeros[i] = 1;
      else if (t == 1)
        ones[i] = 1;
      // build prefix sum
      if (i > 0) {
        zeros[i] += zeros[i - 1];
        ones[i] += ones[i - 1];
      }
    }
    // any number >= 2 can be represented as a
    // prime or sum of one/more primes
    // here we have to take sum of two numbers
    // hence sum of those two numbers should not be
    // 0 or 1
    // 0 sum -> when both numbers are 0
    // 1 sum -> when one is 0 and another is 1
    // total = (all pairs in range) - (zero pairs) - (one + zero pairs)
    int q;
    cin >> q;
    while (q--) {
      int l, r;
      cin >> l >> r;
      int diff = r - l + 1;
      int zero_count = zeros[r - 1] - ((l > 1) ? zeros[l - 2] : 0);
      int one_count = ones[r - 1] - ((l > 1) ? ones[l - 2] : 0);
      int total = (diff * (diff - 1) / 2) -
                  (zero_count * (zero_count - 1) / 2) -
                  (zero_count * one_count);
      cout << total << endl;
    }
  }

  return 0;
}
