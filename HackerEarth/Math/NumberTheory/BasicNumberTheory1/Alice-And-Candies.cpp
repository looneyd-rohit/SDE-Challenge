// https://www.hackerearth.com/practice/math/number-theory/basic-number-theory-1/practice-problems/algorithm/lola-and-candies-36b57b1b/

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
  // Alice and candies

  // int t;
  // cin >> t;
  // while (t--) {

  // }
  int n;
  cin >> n;
  int cnt = 0;
  for (int i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      int f = i;
      int s = n / i;
      if ((f + s) % 2 == 0) {
        cnt++;
      }
    }
  }
  cout << cnt << endl;

  return 0;
}
