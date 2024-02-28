// https://www.hackerearth.com/practice/basic-programming/bit-manipulation/basics-of-bit-manipulation/practice-problems/algorithm/xor-challenge-2420f189/

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

int32_t main() {
  nsync;
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("error.txt", "w", stderr);
#endif

  // int t;
  // cin >> t;
  // while (t--) {

  // }

  int c;
  cin >> c;
  int no_of_bits = log2(c) + 1;
  int a = 0, b = 0;
  vector<int> set_bits;
  REP(i, no_of_bits) {
    if (c & (1 << i)) {
      // bit is set
      set_bits.push_back(i);
    } else {
      a |= (1 << i);
      b |= (1 << i);
    }
  }
  // now generate all the possible bits for set_bits
  long long ans = 0;
  int sz = 1 << (set_bits.size());
  REP(mask, sz) {
    int new_a = a, new_b = b;
    REP(j, set_bits.size()) {
      if (mask & (1 << j)) {
        new_a |= (1 << set_bits[j]);
      } else {
        new_b |= (1 << set_bits[j]);
      }
    }
    ans = max(ans, new_a * 1LL * new_b);
  }
  cout << ans << endl;

  return 0;
}
