// https://cses.fi/problemset/task/1745/

#include <bits/stdc++.h>
using namespace std;
const int M = 1e9+7;
#define int long long
const int s = 1e5 + 1;
const int INF = 1e10;
const int NINF = 1e10 * (-1);
#define ull unsigned long long
#define ll long long
#define lb lower_bound
#define nsync                         \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL);
#define t()   \
	int t;    \
	cin >> t; \
	while (t--)

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
//     int mid = (lo + hi) >> 1;
//     long long now = f(mid, x);
//     long long after = f(mid+1, x);
//     if (now > after) lo = mid + 1;
//     else hi = mid - 1; 
//   }
//   return min(last, m[lo] * x + b[lo]);
// }

int dp[(int)(101)][(int)(1e5+1)];

bool solve(int index, int n, int sum, vector<int>& arr){
	// base case
	if(index >= n){
		return (sum == 0);
	}

	// dp check
	if(dp[index][sum]!=-1) return dp[index][sum];

	bool take = false;
	if(sum >= arr[index]){
		take = solve(index+1, n, sum-arr[index], arr);
	}
	bool notTake = solve(index+1, n, sum, arr);

	return dp[index][sum] = (take || notTake);
}

int32_t main()
{
	nsync;
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
		freopen("error.txt", "w", stderr);
	#endif
	// sieve();
	
	// t()
	// {
		int n;
		cin>>n;
		vector<int> arr(n);
		for(int i=0; i<n; i++) cin>>arr[i];
		// sort(begin(arr), end(arr));


		memset(dp, -1, sizeof(dp));
		vector<int> sums;
		for(int sum=1e5; sum>=1; sum--){
			if(dp[0][sum]==-1){
				solve(0, n, sum, arr);
			}
			if(dp[0][sum]){
				sums.push_back(sum);
			}
		}
		int sz = sums.size();
		cout<<sz<<endl;
		for(int i=sz-1; i>=0; i--){
			cout<<sums[i]<<" ";
		}cout<<endl;

		

		

	// }
	return 0;
}
