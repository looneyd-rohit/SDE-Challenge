// https://codeforces.com/problemset/problem/1392/D

#include <bits/stdc++.h>
using namespace std;
const int M = (int)1e9 + 7;
#define int long long
const int s = 1e5 + 1;
const int INF = 1e10;
const int NINF = 1e10 * (-1);
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

int dp[(int)501][(int)501];

int solve(int prevInd, int k, int n, int l, vector<int>& coordinates, vector<int>& limits){
    // base case
    if(prevInd >= n-1){
        // reached out of bounds
        return 0;
    }

    // dp check
    if(dp[prevInd][k]!=-1) return dp[prevInd][k];

    // transition --> taking O(N) time
    int ans = 1e9;
    for(int ind=prevInd+1; ind<=min(n-1, prevInd+k+1); ind++){
        ans = min(ans, (coordinates[ind]-coordinates[prevInd])*(limits[prevInd]) + solve(ind, k-(ind-prevInd-1), n, l, coordinates, limits));
    }
    return dp[prevInd][k] = ans;
}

int32_t main() {
  nsync;
  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
  #endif
  // sieve();
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    string moves;
    cin>>moves;

    int i=0, total=0;
    vector<bool> visited(n, false);
    while(i<n){
        if(visited[i]) break;

        int j=i, cnt=0;
        while(j<n && moves[j]==moves[i]) visited[j] = true, j++, cnt++;

        // edge case
        if(i==0){
            int k=n-1;
            while(k>i && !visited[k] && moves[k]==moves[i]){
                visited[k]=true;
                k--; cnt++;
            }
        }
        total += (cnt + 2*(cnt==n)) / 3;

        i = j;
    }
    cout<<total<<endl;
    


  }
  return 0;
}
