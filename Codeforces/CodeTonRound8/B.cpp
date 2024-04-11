// 

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

  // B. Bessie and MEX

  int t;
  cin >> t;
  while (t--){
    int n;
    cin>>n;
    vector<int> a(n);
    REP(i, n) cin>>a[i];
    // some observations:
    // after [0...i-1] has been processed for i-th
    // p[i] cannot be less than current mex
    // as all are distinct in p
    // if p[i] > current mex then negative in a[i]
    // if p[i] == current mex then positive in a[i]
    set<int> st;
    REP(i, n+1) st.insert(i);
    REP(i, n){
      if(a[i] > 0){
        cout<<*st.begin()<<" ";
        st.erase(*st.begin());
      }else if(a[i] < 0){
        cout<<(*st.begin()-a[i])<<" ";
        st.erase(*st.begin()-a[i]);
      }
    }
    cout<<endl;
  }
  return 0;
}