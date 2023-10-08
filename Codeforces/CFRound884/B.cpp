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

int primes[(int)1e6+1];
void sieve(){
	for(int i=0; i<=1e6; i++) primes[i] = 1;
	primes[0]=primes[1]=false;
	for(int i=2; i*i<=1e6; i++){
		if(primes[i]){
			for(int j=i*i; j<=1e6; j+=i){
				primes[j] = false;
			}
		}
	}
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
	t()
	{
		int n;
		cin>>n;
		vector<int> arr(n, 1);
		arr[n/2] = 1;
		if(n==1){
			cout<<1<<endl;
		}else if(n == 2){
			cout<<1<<" "<<2<<endl;
		}else{
			arr[0] = 2; arr[n-1] = 3;
			for(int i=1, e=4; i<n-1; i++) if(i != n/2) arr[i] = e++;
			for(int i=0; i<n; i++) cout<<arr[i]<<" ";cout<<endl;
		}
	}
	return 0;
}
