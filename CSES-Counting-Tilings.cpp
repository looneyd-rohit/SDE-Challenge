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

void generate(ull row, ull maskFillingDuetoPrevCol, ull next, unordered_set<ull> &maskFillingForNextDueToCurrent, int n)
{
    // base case
    if (row == n)
    {
        maskFillingForNextDueToCurrent.insert(next);
        return;
    }

    if (maskFillingDuetoPrevCol & (1 << row))
    {
        // if current cell is blocked, then the next cols cell adjacent to it
        // will always be blocked no matter what
        generate(row + 1, maskFillingDuetoPrevCol, next, maskFillingForNextDueToCurrent, n);
    }
    else
    {
        // current cell not blocked

        // place a 2x1 tile (2-->cols, 1-->row)
        // next col adjacent cell gets blocked
        // next = next  (1<<row);
        generate(row + 1, maskFillingDuetoPrevCol, next + (1 << row), maskFillingForNextDueToCurrent, n);
        // next = next ^ (1<<row);

        // place a 1x2 tile (1-->cols, 2-->row)
        // next adjacent cell will never get blocked
        // placing 1x2 possible only when next below cell in same col is free
        if ((row < n - 1) && !(maskFillingDuetoPrevCol & (1 << (row + 1))))
        {
            generate(row + 2, maskFillingDuetoPrevCol, next, maskFillingForNextDueToCurrent, n);
        }
    }
}

ull solve(int col, int maskFillingDuetoPrevCol, int n, int m, vector<vector<ull>> &dp)
{
    // base case
    if (col == m)
    {
        // now if there are no maskFillingDuetoPrevCol then it is satisfied
        if (maskFillingDuetoPrevCol == 0)
            return 1;
        return 0;
    }

    // dp check
    if (dp[col][maskFillingDuetoPrevCol] != -1)
        return dp[col][maskFillingDuetoPrevCol];

    // generate the maskFillingForNextDueToCurrent
    unordered_set<ull> maskFillingForNextDueToCurrent;
    generate(0, maskFillingDuetoPrevCol, 0, maskFillingForNextDueToCurrent, n);

    ull ans = 0;
    for (int nextMask : maskFillingForNextDueToCurrent)
    {
        ans += solve(col + 1, nextMask, n, m, dp) % M;
    }
    return dp[col][maskFillingDuetoPrevCol] = ans % M;
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
    int n, m;
    cin >> n >> m;
    vector<vector<ull>> dp(1001, vector<ull>((1 << 10) + 1, -1));
    cout << solve(0, 0, n, m, dp);

    // }
    return 0;
}
