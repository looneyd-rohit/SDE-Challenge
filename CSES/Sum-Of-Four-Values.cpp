// https://cses.fi/problemset/result/8877690/

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

  // Sum of Four Values
  // int t;
  // cin >> t;
  // while (t--){
    
  // }

  int n, x;
  cin>>n>>x;
  vector<int> arr(n);
  REP(i, n) cin>>arr[i];
  unordered_map<int, pair<int, int> >ump;
  vector<int> ans;
  REP(i, n){
    REPR(j, i+1, n){
      int missing = x - arr[i] - arr[j];
      if(ump.count(missing)){
        ans.push_back(ump[missing].first+1);
        ans.push_back(ump[missing].second+1);
        ans.push_back(i+1);
        ans.push_back(j+1);
        break;
      }
    }
    REPR(j, 0, i){
      int sum = arr[j] + arr[i];
      ump[sum] = make_pair(j, i);
    }
  }
  if(ans.empty()){
    cout<<"IMPOSSIBLE"<<endl;
  }else{
    cout<<ans[0]<<" "<<ans[1]<<" "<<ans[2]<<" "<<ans[3]<<endl;
  }

  return 0;
}
