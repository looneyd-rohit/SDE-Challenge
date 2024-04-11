// https://codeforces.com/contest/1951/problem/B

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

  // B. Battle Cows

  int t;
  cin >> t;
  while (t--){
    int n, k;
    cin>>n>>k;
    k--;
    vector<int> a(n);
    REP(i, n) cin>>a[i];
    int mini = *min_element(begin(a), end(a));
    int maxi = *max_element(begin(a), end(a));
    // cout<<"maxi: "<<maxi<<endl;
    if(mini == a[k]){
      cout<<0<<endl;
    }else if(maxi == a[k]){
      cout<<(n-1)<<endl;
    }else{
      // swap with first greater
      int ind = -1;
      REP(i, k){
        if(a[i] > a[k]){
          ind = i;
          break;
        }
      }
      // cout<<ind<<endl;
      if(ind == -1){
        swap(a[0], a[k]);
        int wins = 0;
        for(int i=1; i<n; i++){
          if(a[i] > a[0]) break;
          wins++;
        }
        cout<<wins<<endl;
      }else{
        swap(a[0], a[k]);
        int wins1 = 0;
        for(int i=1; i<n; i++){
          if(a[i] > a[0]) break;
          wins1++;
        }
        // cout<<wins<<endl;
        swap(a[0], a[k]);

        swap(a[ind], a[k]);
        int wins2 = (ind==0) ? 0 : 1;
        for(int i=ind+1; i<n; i++){
          if(a[i] > a[ind]) break;
          wins2++;
        }
        cout<<max(wins1, wins2)<<endl;
      }
    }
  }
  return 0;
}