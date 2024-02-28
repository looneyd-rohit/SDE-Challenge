// https://codeforces.com/gym/102644/problem/E
#include <bits/stdc++.h>
using namespace std;
// const int M = (int)1e9 + 7;
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

int M = 4294967296;
auto multiplyMatrices(vector<vector<ull>>& a, vector<vector<ull>>& b){
	int n = a.size(), m = a[0].size();
	vector<vector<ull>> ans(n, vector<ull>(m, 0.0));
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			for(int k=0; k<m; k++){
				ans[i][j] += (a[i][k] * b[k][j]) % M;
				ans[i][j] %= M;
			}
		}
	}
	return ans;
}

void printMatrix(vector<vector<int>>& adj){
	int n = adj.size();
	for(int i=0; i<n; i++){
	  	for(int j=0; j<n; j++){
	  		cout<<adj[i][j]<<" ";
	  	}
	  	cout<<endl;
	}
	cout<<"-----------"<<endl;
}
void printArray(vector<ull>& arr){
	for(auto& e: arr) cout<<e<<" ";cout<<endl;
	cout<<"-----------"<<endl;
}

bool isValid(int x, int y){
	if((0<=x && x<8) && (0<=y && y<8)) return true;
	return false;
}

vector<pair<int, int>> moves = {{2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2}};

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

  int k;
  cin>>k;

  // dynamic programming approach: [TLE]
  vector<ull> dp(65, 0);
  dp[0] = 1;    // base case

  // repeat k times
  k++; // one step used up in addition 0...k
  for(int times=0; times<k; times++){
  	// generate next state for each iteration
  	vector<ull> temp(65);
  	// apply transition
  	for(int x=0; x<8; x++){
  		for(int y=0; y<8; y++){
  			for(auto& move: moves){
  				int dx = move.first, dy = move.second;
  				int new_x = x+dx, new_y = y+dy;
  				if(isValid(new_x, new_y)){
  					// lies inside the matrix/grid
  					// cout<<8*new_x+new_y<<endl;
  					// cout<<new_x<<", "<<new_y<<endl;
  					temp[8*new_x+new_y] += dp[8*x+y] % M;
  					// temp[8*new_x+new_y] %= M;
  				}
  			}
  		}
  	}
  	temp[64] += dp[64] % M;    // last state it is not catched
  	temp[64] %= M;		       // inside the above for loops

  	// printArray(dp);
  	// printArray(temp);
  	// apply summation overal 0...k
  	for(int x=0; x<8; x++){
  		for(int y=0; y<8; y++){
  			temp[64]+=dp[8*x+y]%M;
  			temp[64]%=M;
  		}
  	}
  	
  	// swap the states
  	dp = temp;
  }
  cout<<dp[64]<<endl;




  // matrix exponentiation based approach: form the
  // transition matrix first
  // vector<vector<ull>> transition(65, vector<ull>(65, 0)), res(65, vector<ull>(65, 0));
  // for(int x=0; x<8; x++){
  // 	for(int y=0; y<8; y++){
  // 		for(auto& move: moves){
  // 			int dx = move.first, dy = move.second;
  // 			int new_x = x+dx, new_y = y+dy;
  // 			if(isValid(new_x, new_y)){
  // 				transition[8*x+y][8*new_x+new_y] = 1;
  // 			}
  // 		}
  // 	}
  // }
  // for(int i=0; i<65; i++) transition[i][64] = 1;    // used for cumulative addition from 0...k
  // for(int i=0; i<65; i++) res[i][i] = 1;
  // k++;    // one extra needed as we are summing up from 0...k
  //         // so the one step gets wasted on adding up
  // while(k){
  // 	if(k & 1){
  // 		res = multiplyMatrices(res, transition);
  // 	}
  // 	transition = multiplyMatrices(transition, transition);
  // 	k >>= 1;
  // }
  // cout<<res[0][64]<<endl;




  return 0;
}
