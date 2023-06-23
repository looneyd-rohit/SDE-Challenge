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

ull computeLogBase2(ull N)
{
    ull k = 0;
    while ((1 << k) <= N)
    {
        k++;
    }
    return k - 1;
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
    ull n, q;
    cin >> n >> q;
    vector<ull> arr(n, 0);

    ull logBase2N = computeLogBase2(n);
    vector<vector<ull>> matrix(n, vector<ull>(logBase2N + 1, 0));

    for (ull i = 0; i < n; i++)
    {
        cin >> arr[i];
        // range of length building
        matrix[i][0] = arr[i];
    }

    // build the sparse table for finding range minimum queries
    for (ull j = 1; j <= logBase2N; j++)
    {
        for (ull i = 0; i + (1 << j) - 1 < n; i++)
        {
            matrix[i][j] = min(matrix[i][j - 1], matrix[i + (1 << (j - 1))][j - 1]);
        }
    }

    while (q--)
    {
        ull a, b;
        cin >> a >> b;
        // since it is 1-based indexing
        a--;
        b--;
        ull len = b - a + 1;
        ull logBase2Len = computeLogBase2(len);
        ull mini = min(matrix[a][logBase2Len], matrix[b - (1 << logBase2Len) + 1][logBase2Len]);

        cout << mini << endl;
    }
    // }
    return 0;
}
