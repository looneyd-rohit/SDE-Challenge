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
		vector<int> arr(n, -1);
		long long maxi = NINF;
		for(int i=0; i<n; i++){
			cin>>arr[i];
			maxi = max(maxi, arr[i]);
		}

		if(n == 1){
			cout<<arr[0]<<endl;
		}else if(n >= 2){
			// only combination sum of odd with odd or even with even is possible
			long long maxSum = NINF;
			long long oddSum = 0, evenSum = 0;
			for(int i=0; i<n; i+=1){
				if((i & 1)){
					if(arr[i] > 0) oddSum += arr[i];
				}else{
					if(arr[i] > 0) evenSum += arr[i];
				}
				maxSum = max({maxSum, oddSum, evenSum});
			}
			if(maxSum != 0) cout<<maxSum<<endl;
			else cout<<maxi<<endl;
		}
	}
	return 0;
}
