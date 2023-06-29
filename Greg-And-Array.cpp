// https://codeforces.com/problemset/problem/295/A/

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




int32_t main()
{
	nsync;
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
		freopen("error.txt", "w", stderr);
	#endif
	// t()
	// {
		int n, m, k;
		cin>>n>>m>>k;
		vector<int> arr(n, 0);
		for(int i=0; i<n; i++){
			cin>>arr[i];
		}
		vector<vector<int>> operations(m, vector<int>(3, 0));
		for(int i=0; i<m; i++){
			int l, r, d;
			cin>>l>>r>>d;
			operations[i][0] = --l;
			operations[i][1] = --r;
			operations[i][2] = d;
		}
		vector<vector<int>> queries(k, vector<int>(2, 0));
		for(int i=0; i<k; i++){
			int l, r;
			cin>>l>>r;
			queries[i][0] = --l;
			queries[i][1] = --r;
		}

		// using difference array technique with prefix sum to build the array
		// here the queries itself need to be applied multiple times, so
		// overlap occurs between them, hence we need to first compute
		// operation time for each query and then for the array
		vector<ull> modifiedOperationsCount(m+1, 0);
		for(int i=0; i<k; i++){
			int l = queries[i][0], r = queries[i][1];
			modifiedOperationsCount[l] += 1;
			modifiedOperationsCount[r+1] -= 1;
		}

		// take the prefix sum to get actual count of each operation
		for(int i=1; i<m; i++){
			modifiedOperationsCount[i] += modifiedOperationsCount[i-1];
		}

		// get the count of the individual operations that are being applied
		// and take the prefix sum and add to the initial array to get final
		// output
		vector<ull> modifiedOperationsSum(n+100, 0);
		for(int i=0; i<m; i++){
			modifiedOperationsSum[operations[i][0]] += modifiedOperationsCount[i]*operations[i][2];
			modifiedOperationsSum[operations[i][1]+1] -= modifiedOperationsCount[i]*operations[i][2];
		}

		ull sum = 0;
		for(int i=0; i<n; i++){
			sum = sum + modifiedOperationsSum[i];
			// cout<<sum<<" ";
			cout<<arr[i]+sum<<" ";
		}
		cout<<endl;



	// }
	return 0;
}
