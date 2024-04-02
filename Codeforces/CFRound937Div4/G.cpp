// https://codeforces.com/contest/1950/problem/G

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

int dp[17][(1<<16)+1];
int solve(int node, int selected, vector<vector<int> >& adj){
  if(dp[node][selected]!=-1) return dp[node][selected];
  int ans = 0;
  // take the current song
  for(auto& next: adj[node]){
    if((selected & (1<<next))==0){
      // take only songs which are not selected in current path
      ans = max(ans, solve(next, selected | (1<<next), adj)); 
    }
  }
  return dp[node][selected] = (1 + ans);
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

  // G. Shuffling Songs
  int t;
  cin >> t;
  while (t--){
    int n;
    cin>>n;
    vector<pair<string, string> > arr(n);
    REP(i, n) cin>>arr[i].first>>arr[i].second;
    // dp + graph approach, delete some songs in order to satisfy
    // construct a graph based on the adjacent condition
    vector<vector<int> > adj(n);
    for(int i=0; i<n; i++){
      for(int j=i+1; j<n; j++){
        if(arr[i].first==arr[j].first || arr[i].second==arr[j].second){
          adj[i].push_back(j);
          adj[j].push_back(i);
        }
      }
    }
    // now find the longest path in this graph, which will
    // give us the longest length of the playlist
    memset(dp, -1, sizeof(dp));
    // start the playlist from every vertex (try all possibilities)
    int len = 0;
    for(int i=0; i<n; i++){
      len = max(len, solve(i, (1<<i), adj));
    }
    cout<<(n - len)<<endl;
  }

  return 0;
}
