// https://www.hackerearth.com/practice/math/number-theory/basic-number-theory-1/practice-problems/algorithm/prime-array-5e448ef6/

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

const int N = 1e5;
bool sieve[N+1];
void generateSieve(){
	memset(sieve, true, sizeof(sieve));
	sieve[0] = sieve[1] = false;
	for(int i=2; i<=N; i++){
		if(sieve[i]){
			for(int j=2*i; j<=N; j+=i){
				sieve[j] = false;
			}
		}
	}
}

int32_t main() {
  nsync;
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("error.txt", "w", stderr);
#endif
  // Prime Array
  generateSieve();
  int t;
  cin >> t;
  while (t--) {
  	int n;
  	cin>>n;
  	int cnt_ones = 0, cnt_primes = 0;
  	REP(i, n){
  		int t;
  		cin>>t;
  		if(t==1){
  			cnt_ones++;
  		}else if(sieve[t]){
  			cnt_primes++;
  		}
  	}
  	int select_ones = cnt_ones * (cnt_ones - 1) / 2;
  	// product of three numbers is prime only
  	// when two of them are 1 and other is prime
  	// no. of ways = nC2 * no. of primes
  	cout<<(select_ones * cnt_primes)<<endl;
  }

  return 0;
}
