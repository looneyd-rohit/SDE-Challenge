// https://codeforces.com/contest/1946/problem/C

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ull unsigned long long
#define ll long long
#define REP(i, n) for (int(i) = 0; (i) < (n); (i)++)
#define nsync                                                                  \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);                                                               \
  cout.tie(NULL);

// constant
const int M = (int)(1e9 + 7);
const int s = 1e5 + 1;
const int INF = 3e18L + 5;
const int INF64 = 1e18;
const int NINF = 1e18 * (-1);

void fun() { cout << "MF World!!!" << endl; }

int cutDFS(int node, int parent, int& k, int mid, unordered_map<int, vector<int> > &adj, vector<int>& dp) {
  // need to perform a total of k cuts, with each subtree
  // having atleast mid no. of nodes
  dp[node] = 1;
  for(auto& next: adj[node]){
    if(next!=parent){
      dp[node] += cutDFS(next, node, k, mid, adj, dp);
    }
  }
  if(dp[node]>=mid && k>0){
    // perform a cut
    dp[node] = 0;
    k--;
  }
  return dp[node];
}

bool isPossible(unordered_map<int, vector<int> > &adj, int n, int k, int mid, vector<int>& dp) {
  int res = cutDFS(0, -1, k, mid, adj, dp);
  return (res >= mid && k == 0);
}

int32_t main() {
  nsync;
  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
  #endif
  // C. Tree Cutting
  int t;
  cin >> t;
  while (t--) {

    int n, k;
    cin >> n >> k;
    unordered_map<int, vector<int> > adj;
    int u, v;
    REP(i, n - 1) {
      cin >> u >> v;
      adj[u - 1].push_back(v - 1);
      adj[v - 1].push_back(u - 1);
    }
    // for any cutting we see that the minimum no. of nodes
    // in each connected component is atleast 1 and
    // the maximum no. of nodes will be atleast 
    // floor(n/(k+1))  here we can apply binary search
    // on the range, since the function satisfies
    // the monotonicity property
    int low = 1, high = n / (k + 1);
    vector<int> dp(n, 0);
    while(low <= high){
      int mid = low + ((high - low) >> 1);
      if(isPossible(adj, n, k, mid, dp)){
        low = mid + 1;
      }else{
        high = mid - 1;
      }
      fill(begin(dp), end(dp), 0);
    }
    cout<<high<<endl;
  }
  return 0;
}
