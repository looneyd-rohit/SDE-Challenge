// https://www.hackerearth.com/problem/algorithm/the-game-of-oxa-bb3d2676/

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

void fun() { cout << "Magi World!!!" << endl; }

int operate(int a, int b, int c) {
  c = c % 3;
  if (c == 0) {
    // OR
    return (a | b);
  } else if (c == 1) {
    // XOR
    return (a ^ b);
  } else {
    // ADD
    return (a + b);
  }
}

int32_t main() {
  nsync;
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("error.txt", "w", stderr);
#endif
  // The Game of OXA

  int t;
  cin >> t;
  while (t--) {
    string str;
    cin >> str;
    int n;
    cin >> n;
    vector<int> arr(n);
    REP(i, n) cin >> arr[i];
    // generate all the subsets and try out
    int sz = (1 << n);
    int ans = 0;
    REP(mask, sz) {
      int oxa = -1;
      int c = 0;
      REP(j, n) {
        if (mask & (1 << j)) {
          // bit is set
          if (oxa == -1) {
            // no number was chosen
            oxa = arr[j];
          } else {
            // number has been chosen
            oxa = operate(oxa, arr[j], c);
            c++;
          }
        }
      }
      ans = max(ans, oxa);
    }
    if (ans & 1) {
      if (str == "Odd") {
        cout << "Monk" << endl;
      } else {
        cout << "Mariam" << endl;
      }
    } else {
      if (str == "Even") {
        cout << "Monk" << endl;
      } else {
        cout << "Mariam" << endl;
      }
    }
  }

  return 0;
}
