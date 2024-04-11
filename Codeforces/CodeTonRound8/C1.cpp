// https://codeforces.com/contest/1942/problem/C1

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

  // C1. Bessie's Birthday Cake (Easy Version)

  int t;
  cin >> t;
  while (t--){
    int n,x,y;
    cin>>n>>x>>y;
    set<int> st;
    REP(i, x){
      int t;
      cin>>t;
      st.insert(t-1);
    }
    int total = x - 2;    // the x sided closed polygon results in x-2 triangles
    // now for the not chosen sides we try out
    // if they can form a triangle or not
    for(auto& e: st){
      int e_1 = (e + 1) % n;
      int e_2 = (e + 2) % n;
      if(!st.count(e_1) && st.count(e_2)) total++;
    }
    cout<<total<<endl;
  }
  return 0;
}