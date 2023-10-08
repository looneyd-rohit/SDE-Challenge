#include <bits/stdc++.h>
#include <iostream>
using namespace std;
const int M = 1e9 + 7;
#define int long long
const int s = 1e5 + 1;
const int INF = 1e17;
const int NINF = 1e17 * (-1);
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

int primes[(int)1e6+1], lprimes[(int)1e6+1];
void sieve(){
	for(int i=0; i<=1e6; i++) primes[i] = 1, lprimes[i]=i;
	primes[0]=primes[1]=false;
	lprimes[0]=lprimes[1]=-1;
	for(int i=2; i*i<=1e6; i++){
		if(primes[i]){
			lprimes[i] = i;
			for(int j=i*i; j<=1e6; j+=i){
				primes[j] = false;
				lprimes[j] = min(lprimes[j], i);
			}
		}
	}
}

unordered_set<int> calculateDivisors(int n){
	unordered_set<int> divisors;
	divisors.insert(1);
	divisors.insert(n);
	while(n > 1){
		int lowprime = lprimes[n];
		while(n % lowprime == 0){
			divisors.insert(lowprime);
			divisors.insert(n/lowprime);
			n /= lowprime;
		}
	}
	return divisors;
}


int32_t main()
{
	nsync;
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
		freopen("error.txt", "w", stderr);
	#endif
	sieve();
	t()
	{
		int n;
		cin>>n;
		if(n == 1){
			cout<<'a'<<endl;
		}else{
			// calculate the divisors of given n
			unordered_set<int> divisors;
			divisors.insert(1);
			divisors.insert(n);
			for(int i=2; i*i<=n; i++)
				if((n%i)==0){
					divisors.insert(i);
					divisors.insert(n/i);
				}
			// for(auto& e: divisors) cout<<e<<" ";cout<<endl;
			vector<int> arr(n, 0);
			for(int i=0; i<n; i++){
				// i-th position can have similarity with (i+divisor) position
				// according to observation
				for(auto& divisor: divisors){
					if((i+divisor) < n && arr[i]==arr[(i+divisor)]){
						arr[(i+divisor)]++;
					}
				}
			}
			for(int i=0; i<n; i++){
				cout<<(char)('a'+arr[i]);
			}cout<<endl;
		}
	}
	return 0;
}
