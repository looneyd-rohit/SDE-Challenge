// https://codeforces.com/gym/102644/problem/A
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


auto multiplyMatrices(vector<vector<double>>& a, vector<vector<double>>& b){
	int n = a.size(), m = a[0].size();
	vector<vector<double>> ans(n, vector<double>(m, 0.0));
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			for(int k=0; k<m; k++){
				ans[i][j] += a[i][k] * b[k][j];
			}
		}
	}
	return ans;
}

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

  ull n;
  cin>>n;
  double p;
  cin>>p;
  // approach 1: recursive + binary exponentiation
  // T.C ~ O(log(n))
  // double prob_after_n = 0.0;    // stores the result -> prob
  // 								// of switch after n minutes
  // 								// starting from any state
  // while(n){
  // 	if(n & 1){
  // 		prob_after_n = (1-p) * prob_after_n + (1-prob_after_n)*p;
  // 	}
  // 	p = 2 * p * (1 - p);
  // 	n >>= 1;
  // }
  // cout<<(1-prob_after_n)<<endl;    // print prob of no switch

  // approach 2: using matrix exponentiation (we need a
  // separate multiplication function for matrices)
  // T.C ~ O(2^3 * log(n))
  vector<vector<double>> probs(2, vector<double>(2, 0.0));
  probs[0][0] = probs[1][1] = (1-p);
  probs[0][1] = probs[1][0] = p;
  // probs -> prob change after 1 minute
  vector<vector<double>> res(2, vector<double>(2, 1.0));
  res[0][1] = res[1][0] = 0.0;
  // initialize res - as identity matrix (satisfy base case)
  while(n){
  	if(n & 1){
  		res = multiplyMatrices(res, probs);
  	}
  	probs = multiplyMatrices(probs, probs);
  	n >>= 1;
  }
  cout<<(res[0][0])<<endl;
  return 0;
}
