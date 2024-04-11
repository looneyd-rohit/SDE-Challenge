// https://codeforces.com/contest/1955/problem/B

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

  // B. Progressive Square

  int t;
  cin >> t;
  while (t--){
    int n,c,d;
    cin>>n>>c>>d;
    multiset<int> mst;
    REP(i, n){
      REP(j, n){
        int t;
        cin>>t;
        mst.insert(t);
      }
    }
    bool flag = true;
    vector<vector<int> > grid(n, vector<int>(n));
    grid[0][0] = *mst.begin();
    mst.erase(mst.find(grid[0][0]));
    REP(i, n){
      REP(j, n){
        if(i==0 && j==0) continue;
        if(j > 0){
          int next = grid[i][j-1] + d;
          if(!mst.count(next)){
            flag = false;
            break;
          }
          grid[i][j] = next;
          mst.erase(mst.find(next));
        }
        if(i > 0 && j==0){
          int next2 = grid[i-1][j] + c;
          if(!mst.count(next2)){
            flag = false;
            break;
          }
          grid[i][j] = next2;
          mst.erase(mst.find(next2));
        }
      }
      if(!flag) break;
    }
    if(flag) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
  }
  return 0; 
}