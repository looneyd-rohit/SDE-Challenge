// https://codeforces.com/contest/1942/problem/A

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

  // A. Farmer John's Challenge

  int t;
  cin >> t;
  while (t--){
    int n,k;
    cin>>n>>k;
    if(k==1){
      REP(i, n) cout<<i+1<<" ";cout<<endl;
    }else if(k==n){
      REP(i, n) cout<<1<<" ";cout<<endl;
    }else{
      cout<<-1<<endl;
    }
  }
  return 0;
}