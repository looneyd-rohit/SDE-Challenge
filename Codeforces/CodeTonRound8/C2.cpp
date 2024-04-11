// https://codeforces.com/contest/1942/problem/C2

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

  // C2. Bessie's Birthday Cake (Hard Version)

  int t;
  cin >> t;
  while (t--){
    int n,x,y;
    cin>>n>>x>>y;
    vector<int> a(x);
    REP(i, x){
      int t;
      cin>>t;
      a[i] = t-1;
    }
    sort(begin(a), end(a));
    int total = x - 2;    // the x sided closed polygon results in x-2 triangles
    // now we need to figure out how we can use the
    // extra y selections
    vector<int> odd, even;
    REP(i, x){
      int next = (i == x-1) ? a[0] + n : a[i+1];
      int diff = next - a[i] - 1;
      if(diff == 1) total++;
      else if(diff > 1){
        if(diff & 1) odd.push_back(diff);
        else even.push_back(diff);
      }
    }
    sort(begin(odd), end(odd));
    sort(begin(even), end(even));
    for(auto& diff: odd){
      if(y < diff/2){
        total += y*2;
        y = 0;
        break;
      }
      y -= diff/2;
      total += diff;
    }
    for(auto& diff: even){
      if(y < diff/2){
        total += y*2;
        y = 0;
        break;
      }
      y -= diff/2;
      total += diff;
    }
    cout<<total<<endl;
  }
  return 0;
}