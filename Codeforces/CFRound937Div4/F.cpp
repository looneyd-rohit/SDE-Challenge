// https://codeforces.com/contest/1950/problem/F

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

int log2Floor(int n){
  int res = 0, p = 1;
  while(p < n){
    p *= 2;
    res++;
  }
  return res;
}

int32_t main()
{
  nsync;
  /*
  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
  #endif
  */

  // F. 0, 1, 2, Tree!
  int t;
  cin >> t;
  while (t--){
    int a,b,c;
    cin>>a>>b>>c;
    // in any tree, no. of nodes having 0 children (left)
    // is always equal to no. of nodes with 2 children + 1
    if(c != a+1){
      cout<<-1<<endl;
    }else{
      // first get initial height of tree assuming it to be
      // a full binary tree
      // full binary tree always has leaf nodes of the order
      // in powers of 2
      int l = log2Floor(c);    // nearest power of 2 just >= c
      int rem = (1LL << l) - c;
      if(b >= rem) b -= rem;  // deficit is covered up by b
      else b = 0;
      int extra = ceil((b * 1.0) / c);
      cout<<(l+extra)<<endl;
    }
  }

  return 0;
}
