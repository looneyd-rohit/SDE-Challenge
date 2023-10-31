// https://atcoder.jp/contests/dp/tasks/dp_j

#include <bits/stdc++.h>
using namespace std;
const int M = (int)1e9 + 7;
#define int long long
const int s = 1e5 + 1;
const long long INF64 = 1e18;
const int INF = 1e18;
const int NINF = 1e18 * (-1);
#define ull unsigned long long
#define ll long long
#define lb lower_bound
#define nsync                                                                  \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);                                                               \
  cout.tie(NULL);

// int primes[(int)1e6+5], lprimes[(int)1e6+5];
// void sieve(){
// 	for(int i=0; i<=1e6; i++) primes[i] = 1, lprimes[i]=-1;
// 	primes[0]=primes[1]=false;
// 	// lprimes[0]=lprimes[1]=-1;
// 	for(int i=2; i*i<=1e6; i++){
// 		if(primes[i]){
// 			lprimes[i] = i;
// 			for(int j=i*i; j<=1e6; j+=i){
// 				primes[j] = false;
// 				if(lprimes[j]==-1) lprimes[j] = i;
// 				// lprimes[j] = min(lprimes[j], i);
// 			}
// 		}
// 	}
// }

// unordered_set<int> calculateDivisors(int n){
// 	unordered_set<int> divisors;
// 	divisors.insert(1);
// 	divisors.insert(n);
// 	while(n > 1){
// 		int lowprime = lprimes[n];
// 		while(n % lowprime == 0){
// 			divisors.insert(lowprime);
// 			divisors.insert(n/lowprime);
// 			n /= lowprime;
// 		}
// 	}
// 	return divisors;
// }

// vector<int> m, b;

// bool bad(int f1, int f2, int f3) {
//   return (b[f3] - b[f1]) * (m[f1] - m[f2]) >=
//          (b[f2] - b[f1]) * (m[f1] - m[f3]);
// }

// void add(long long m_, long long b_) {
//   m.push_back(m_); b.push_back(b_); // push in CHT
//   int sz = m.size();
//   // check if it can be kept or not
//   while(sz >= 3 && bad(sz - 3, sz - 2, sz - 1)) {
//     m.erase(m.end() - 2); // remove f2's m
//     b.erase(b.end() - 2); // remove f2's b
//     sz--; // size is decreased by 1
//   }
// }

// int f(int i, int x) { return m[i] * x + b[i]; }
// long long query (long long x) {
// 	int size = m.size();
//   long long last = m[size - 1] * x + b[size - 1];
//   int lo = 0, hi = size - 2;
//   while (lo <= hi) {
//     int mid = (lo + hi) > > 1;
//     long long now = f(mid, x);
//     long long after = f(mid+1, x);
//     if (now > after) lo = mid + 1;
//     else hi = mid - 1;
//   }
//   return min(last, m[lo] * x + b[lo]);
// }

vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
  unordered_set<int> m(nums1.begin(), nums1.end());
  vector<int> res;
  for (auto a : nums2)
    if (m.count(a)) {
      res.push_back(a);
      m.erase(a);
    }
  return res;
}

double curr[(int)301][(int)301];
double pre[(int)301][(int)301];

int32_t main() {
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

  int n;
  cin >> n;
  int C1 = 0, C2 = 0, C3 = 0;
  for (int i = 0; i < n; i++) {
    int t;
    cin >> t;
    C1 += t == 1;
    C2 += t == 2;
    C3 += t == 3;
  }
  memset(curr, 0.0, sizeof(curr));
  memset(pre, 0.0, sizeof(pre));
  // dp[c0][c1][c2][c3] --> expected no. of operations to reach
  // (N, 0, 0, 0) from given state
  for (int c3 = 0; c3 <= C3; c3++) {
    for (int i = 0; i <= n; i++)
      for (int j = 0; j <= n; j++)
        pre[i][j] = curr[i][j];
    for (int c2 = 0; c2 <= n; c2++) {
      for (int c1 = 0; c1 <= n; c1++) {
        int c0 = n - c1 - c2 - c3;
        // since total no. of plates should be equal to n
        if (c0 == n) {
          curr[c1][c2] = 0;
          continue;
        }

        double e1 = 0.0, e2 = 0.0, e3 = 0.0;
        if (c1 > 0)
          e1 = curr[c1 - 1][c2];
        if (c2 > 0)
          e2 = curr[c1 + 1][c2 - 1];
        if (c3 > 0)
          e3 = pre[c1][c2 + 1];

        double e = (n + (c1 * e1) + (c2 * e2) + (c3 * e3)) / (n - c0);
        curr[c1][c2] = e;
      }
    }
  }

  cout << fixed << setprecision(10) << curr[C1][C2] << endl;

  return 0;
}
