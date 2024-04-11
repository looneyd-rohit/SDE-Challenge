// https://codeforces.com/contest/1955/problem/F

#include <bits/stdc++.h>
using namespace std;
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

  // F. Unfair Game

  int t;
  cin >> t;
  while (t--){
    int n1, n2, n3, n4;
    cin>>n1>>n2>>n3>>n4;
    int maxi = 0;
    if((n1&1) && (n2&1) && (n3&1)){
      maxi = 1;
    }
    maxi += (n1>>1) + (n2>>1) + (n3>>1) + (n4>>1);
    cout<<maxi<<endl;
  }
  return 0; 
}