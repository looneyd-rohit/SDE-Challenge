// https://codeforces.com/gym/102644/problem/G
#include <bits/stdc++.h>
using namespace std;
const int M = (int)1e9 + 7;
#define int long long
const int s = 1e5 + 1;
const long long INF64 = 1e18;
const int INF = 3e18L + 5;
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

// vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
//   unordered_set<int> m(nums1.begin(), nums1.end());
//   vector<int> res;
//   for (auto a : nums2)
//     if (m.count(a)) {
//       res.push_back(a);
//       m.erase(a);
//     }
//   return res;
// }

void printMatrix(vector<vector<int>> &adj) {
  int n = adj.size();
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << adj[i][j] << " ";
    }
    cout << endl;
  }
  cout << "-----------" << endl;
}
void printArray(vector<int> &arr) {
  for (auto &e : arr)
    cout << e << " ";
  cout << endl;
  cout << "-----------" << endl;
}

auto multiplyMatrices(vector<vector<int>> &a, vector<vector<int>> &b) {
  int n = a.size(), m = a[0].size();
  vector<vector<int>> ans(n, vector<int>(m, 0));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      for (int k = 0; k < m; k++) {
        ans[i][j] += (a[i][k] * b[k][j]) % M;
        ans[i][j] %= M;
      }
    }
  }
  return ans;
}

auto modifiedMultiplyMatrices(vector<vector<int>> &a, vector<vector<int>> &b) {
  int n = a.size(), m = a[0].size();
  vector<vector<int>> ans(n, vector<int>(n, INF));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      for (int k = 0; k < m; k++) {
        ans[i][j] = min(ans[i][j], (a[i][k] + b[k][j]));
      }
    }
  }
  return ans;
}

bool isValid(int x, int y) {
  if ((0 <= x && x < 8) && (0 <= y && y < 8))
    return true;

  return false;
}

vector<pair<int, int>> moves = {{2, 1}, {2, -1}, {-2, 1}, {-2, -1},
                                {1, 2}, {1, -2}, {-1, 2}, {-1, -2}};

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

  int n, k;
  cin >> n >> k;
  vector<int> a(n), c(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int i = 0; i < n; i++)
    cin >> c[i];

  int p, q, r;
  cin >> p >> q >> r;

  if (k < n) {
    cout << a[k] << endl;
    return 0;
  }

  /*
  (base solution)
  // converting to a dp based solution
  vector<int> dp(n + 3);
  for (int i = 0; i < n; i++)
    dp[i] = a[i];
  // initialize initial multipliers as required
  dp[n] = 1;         // acts as multiplier of p
  dp[n + 1] = n;     // acts as multiplier of q
  dp[n + 2] = n * n; // acts as multiplier of r

  for (int i = n; i <= k; i++) {
    // starting from n till k
    vector<int> new_dp(n + 3);
    // update multipliers for the next step
    // as they change on every step
    new_dp[n] = dp[n];
    new_dp[n + 1] = dp[n + 1] + dp[n];
    new_dp[n + 2] = dp[n + 2] + 2 * dp[n + 1] + dp[n];

    // generate the next term;
    new_dp[n - 1] += p * dp[n];
    new_dp[n - 1] += q * dp[n + 1];
    new_dp[n - 1] += r * dp[n + 2];
    // new_dp[n-1] = 1 * p + (i * q) + (i * i * r);
    for (int j = 0; j < n; j++) {
      new_dp[n - 1] += (c[j] * dp[n - 1 - j]) % M;
      new_dp[n - 1] %= M;
    }
    for (int j = 0; j < n - 1; j++) {
      new_dp[j] = dp[j + 1];
    }
    // update dp
    dp = new_dp;
  }
  cout << dp[n - 1] << endl;
  */

  // matrix exponentiation solution
  vector<vector<int>> transitions(n + 3, vector<int>(n + 3));
  transitions[n][n] = 1;

  transitions[n][n + 1] = 1;
  transitions[n + 1][n + 1] = 1;

  transitions[n][n + 2] = 1;
  transitions[n + 1][n + 2] = 2;
  transitions[n + 2][n + 2] = 1;

  transitions[n][n - 1] = p;
  transitions[n + 1][n - 1] = q;
  transitions[n + 2][n - 1] = r;

  for (int j = 0; j < n; j++) {
    transitions[n - 1 - j][n - 1] = c[j];
  }

  for (int j = 0; j < n - 1; j++) {
    transitions[j + 1][j] = 1;
  }

  vector<int> dp(n + 3);
  for (int i = 0; i < n; i++)
    dp[i] = a[i];
  // initialize initial multipliers as required
  dp[n] = 1;         // acts as multiplier of p
  dp[n + 1] = n;     // acts as multiplier of q
  dp[n + 2] = n * n; // acts as multiplier of r

  /*
  (further optimization to matrix exponentiation)

  for(int rep=0; rep<k-n+1; rep++){
    vector<int> new_dp(n+3);
    for(int i=0; i<n+3; i++){
      for(int j=0; j<n+3; j++){
        new_dp[j] += (dp[i] * transitions[i][j]) % M;
        new_dp[j] %= M;
      }
    }
    dp = new_dp;
  }
  */
  vector<vector<int>> res(n + 3, vector<int>(n + 3, 0));
  for (int i = 0; i < n + 3; i++)
    res[i][i] = 1;

  int t = k - n + 1;
  while (t) {
    if (t & 1) {
      res = multiplyMatrices(res, transitions);
    }
    transitions = multiplyMatrices(transitions, transitions);
    t >>= 1;
  }

  vector<int> new_dp(n + 3);
  for (int i = 0; i < n + 3; i++) {
    for (int j = 0; j < n + 3; j++) {
      new_dp[j] += (long long)(dp[i] * res[i][j]) % M;
      new_dp[j] %= M;
    }
  }

  cout << new_dp[n - 1] << endl;

  return 0;
}
