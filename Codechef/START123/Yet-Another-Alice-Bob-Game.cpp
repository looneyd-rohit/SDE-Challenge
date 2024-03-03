// https://www.codechef.com/problems/YETALICEBOB?tab=statement

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
  // Yet Another Alice Bob Game
  int t;
  cin >> t;
  while (t--) {
    int n, a, b;
    cin >> n >> a >> b;
    // case: a>b
    // alice always wins
    // if n>a>b -> alice removes 1 stone until
    // remaining stones <= a
    // else n<=a then alice wins in first turn
    if (a > b) {
      cout << "alice" << endl;
    } else if (a < b) { // case: a<b
      // alice wins in the first move when a>=n
      if (a >= n)
        cout << "alice" << endl;
      // since
      // if a<n<b
      // then at second turn bob wins
      // else if a<b<n
      // similar to when a>b
      // here bob will win always
      else
        cout << "bob" << endl;
    } else {
      // case: a=b
      // here if n%(a+1) when turn is of alice
      // n is the remaining stones then bob wins
      // and vice versa (counting to 21 game)
      if (n % (a + 1) == 0)
        cout << "bob" << endl;
      else
        cout << "alice" << endl;
    }
  }

  return 0;
}
