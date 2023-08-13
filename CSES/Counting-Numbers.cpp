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

ull solve(int n, int prev, bool tight, string &s, vector<vector<vector<ull>>> &dp)
{
    // base case
    if (n == 0)
    {
        return 1;
    }

    // dp check
    if (dp[n][prev][tight] != -1)
        return dp[n][prev][tight];

    int ub = tight ? s[s.length() - n] - '0' : 9;
    ull ans = 0;
    for (int digit = 0; digit <= ub; digit++)
    {
        if (prev != digit)
        {
            if (digit == 0 && prev == 10)
            {
                ans = ans + solve(n - 1, prev, tight & (digit == ub), s, dp);
            }
            else
            {
                ans = ans + solve(n - 1, digit, tight & (digit == ub), s, dp);
            }
        }
    }
    return dp[n][prev][tight] = ans;
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
    ull l, r;
    cin >> l >> r;
    ull ml = l;
    if (l > 0)
        ml = l - 1;
    if (l == 0 && r == 0)
    {
        cout << 1 << endl;
        return 0;
    }

    string L, R;
    L = to_string(ml);
    R = to_string(r);
    // cout<<L<<" to "<<R<<endl;
    vector<vector<vector<ull>>> dp1(L.length() + 1, vector<vector<ull>>(11, vector<ull>(2, -1)));
    ull left = solve(L.length(), 10, true, L, dp1);
    vector<vector<vector<ull>>> dp2(R.length() + 1, vector<vector<ull>>(11, vector<ull>(2, -1)));
    ull right = solve(R.length(), 10, true, R, dp2);
    cout << right - left + ((l == 0) ? 1 : 0) << endl;
    // }
    return 0;
}
