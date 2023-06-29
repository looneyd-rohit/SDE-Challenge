https://codeforces.com/problemset/submission/1132/211372727
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

int dp[501][501];
ull solve(ull i, ull j, vector<pair<char, int>>& groups){
	// base case
	if(i > j){
		return 0;
	}

	// dp check
	if(dp[i][j]!=-1) return dp[i][j];


	ull ans = 1 + solve(i+1, j, groups);
	for(int group=i+2; group<=j; group+=1){
		if(groups[i].first == groups[group].first){
			ans = min(ans, solve(i+1, group-1, groups) + solve(group, j, groups));
		}
	}
	return dp[i][j] = ans;
}

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
		int n;
		cin>>n;
		string str;
		cin>>str;

		// merge dp pattern
		vector<pair<char, int>> groups;
		char prev = str[0];
		int cnt = 1;
		for(int i=1; i<n; i++){
			if(str[i]==prev){
				cnt++;
			}else{
				groups.push_back({prev, cnt});
				cnt=1;
				prev = str[i];
			}
		}
		groups.push_back({prev, cnt});
		// for(auto&e :groups) cout<<e.first<<" "<<e.second<<endl;
		memset(dp, -1, sizeof(dp));
		cout<<solve(0, groups.size()-1, groups)<<endl;


	// }
	return 0;
}