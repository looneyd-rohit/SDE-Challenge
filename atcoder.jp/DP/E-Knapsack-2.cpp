// https://atcoder.jp/contests/dp/tasks/dp_e

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

int dp[(int)(101)][(int)(1e5+1)];

int solve(int index, int maxVal, vector<int>& wt, vector<int>& val){
	// base case
	if(index == -1){
		// maxVal can be achieved
		if(maxVal == 0) return 0;
		// maxVal cannot be achieved
		return INF;
	}

	// dp check
	if(dp[index][maxVal]!=-1) return dp[index][maxVal];

	// take the current index element
	int take = INF;
	if(maxVal-val[index]>=0){
		take = wt[index] + solve(index-1, maxVal-val[index], wt, val);
	}

	// don't take the current element
	int notTake = solve(index-1, maxVal, wt, val);

	return dp[index][maxVal] = min(take, notTake);
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
		int n, w;
		cin>>n>>w;
		vector<int> wt(n), val(n);
		for(int i=0; i<n; i++){
			cin>>wt[i];
			cin>>val[i];
		}
		// instead of writing a function that returns maximum value
		// write a function that returns minimum w <= wt, such that
		// a particular value can be achieved, value ranges from 
		// 0 to 1e5;
		// memoization:
		memset(dp, -1, sizeof(dp));
		for(int maxVal=1e5; maxVal>=0; maxVal--){
			if(solve(n-1, maxVal, wt, val) <= w){
				cout<<maxVal<<endl;
				break;
			}
		}

	// }
	return 0;
}
