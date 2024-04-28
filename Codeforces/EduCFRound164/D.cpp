// https://codeforces.com/contest/1954/problem/D

#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define ull unsigned long long
#define ll long long
#define REP(i, n) for (int(i) = 0; (i) < (n); (i)++)
#define REPR(i, m, n) for (int(i) = (m); (i) < (n); (i)++)
#define REPRR(i, m, n) for (int(i) = (m); (i) > (n); (i)--)
#define nsync                       \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL);                    \
  cout.tie(NULL);

// constant
// const int M = (int)(1e9 + 7);
const int M = (int)(998244353);
const int s = 1e5 + 1;
const int INF = 3e18L + 5;
const int INF64 = 1e18;
const int NINF = 1e18 * (-1);

void fun() { cout << "MF World!!!" << endl; }

int dp[5001][5001];
int cnt[5001];

int32_t main(){
  nsync;
  /*
  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
  #endif
  */

  // D. Colored Balls

  // int t;
  // cin >> t;
  // while (t--){
    
  // }
  int n;
  cin>>n;
  vector<int> a(n);
  REP(i, n) cin>>a[i];
  sort(begin(a), end(a));
  // dp[i][j] --> count of subsets with
  // sum i and maximum element j
  memset(dp, 0, sizeof(dp));
  memset(cnt, 0, sizeof(cnt));
  // base cases
  dp[a[0]][a[0]] = 1;    // for 0-th element
  cnt[a[0]] = 1;    // for 0-th element

  REPR(i, 1, n){
    // consider a[i] as the maximum element
    // and compute the count of subsets for
    // all possible sums with a[i] as maximum
    REPRR(j, 5000, a[i]){
      dp[j][a[i]] += (cnt[j - a[i]]);
      dp[j][a[i]] %= M;
    }
    // update the counts considering a[i]
    REPRR(j, 5000, a[i]){
      cnt[j] += (cnt[j - a[i]]);
      cnt[j] %= M;
    }
    // default case
    dp[a[i]][a[i]]++;
    cnt[a[i]]++;
  }
  int ans = 0;
  REPR(i, 1, 5001){
    REPR(j, 1, i+1){
      // sum --> i
      // max element --> j
      ans += max(j, ((i+1)>>1)) * dp[i][j];
      ans %= M;
    }
  }
  cout<<ans<<endl;
  return 0; 
}