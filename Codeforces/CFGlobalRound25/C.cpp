// https://codeforces.com/contest/1951/problem/C

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ull unsigned long long
#define ll long long
#define REP(i, n) for (int(i) = 0; (i) < (n); (i)++)
#define REPR(i, n, m) for (int(i) = (n); (i) < (m); (i)++)
#define nsync                       \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL);                    \
  cout.tie(NULL);

// constant
const int M = (int)(1e9 + 7);
const int s = 1e5 + 1;
const int INF = 3e18L + 5;
const int INF64 = 1e18;
const int NINF = 1e18 * (-1);

void fun() { cout << "MF World!!!" << endl; }


int32_t main(){
  nsync;
  /*
  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
  #endif
  */

  // C. Ticket Hoarding

  ull t;
  cin >> t;
  while (t--){
    ull n,m,k;
    cin>>n>>m>>k;
    vector<ull> a(n);
    REP(i, n) cin>>a[i];
    sort(begin(a), end(a));
    ull cost = 0, buffer = 0;
    REP(i, n){
      ull buy = min(m, k);
      cost += (a[i] + buffer) * buy;
      buffer += buy;
      k -= buy;
      if(k==0) break;
    }
    cout<<cost<<endl;
  }
  return 0; 
}