// https://codeforces.com/problemset/problem/597/C

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

const int N = 1e5+5;
const int K = 12;

class SGTree{
public:
  vector<int> segarr;
  SGTree(int n=0){
    this->segarr.resize(4*n+1, 0);
  }
  void build(int index,int low, int high, vector<int>& arr){
    if(low==high){
      this->segarr[index] = arr[low];
      return;
    }
    int mid = low + ((high - low) >> 1);
    build(2*index+1, low, mid, arr);
    build(2*index+2, mid+1, high, arr);
    this->segarr[index] = this->segarr[2*index+1] + this->segarr[2*index+2];
  }
  void update(int index, int low, int high, int ind, int val){
    if(low == high){
      this->segarr[index] += val;
      return;
    }
    int mid = low + ((high - low) >> 1);
    if(ind <= mid){
      update(2*index+1, low, mid, ind, val);
    }else{
      update(2*index+2, mid+1, high, ind, val);
    }
    this->segarr[index] = this->segarr[2*index+1] + this->segarr[2*index+2];
  }
  int query(int index, int low, int high, int l, int r){
    // no overlap
    if(r<low || high<l) return 0;

    // full overlap
    if(l<=low && high<=r) return this->segarr[index];

    // partial overlap
    int mid = low + ((high - low) >> 1);
    int left = query(2*index+1, low, mid, l, r);
    int right = query(2*index+2, mid+1, high, l, r);
    return (left + right);
  }
};

int32_t main(){
  nsync;
  /*
  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
  #endif
  */

  // C. Subsequences
  // int t;
  // cin >> t;
  // while (t--){
    
  // }

  int n, k;
  cin>>n>>k;
  vector<int> arr(n);
  REP(i, n) cin>>arr[i];
  // dp appraoch: dp[i][j] --> stores the count of subsequences
  // of length i, ending at element j
  // all elements will be considered 1 length subsequence
  // so dp[1][j] = 1, for any j
  // for all others dp[i][j] += dp[i-1][1] + dp[i-1][2] + ... + dp[i-1][j-1]
  // this can be optimized by using segment trees
  vector<SGTree*> sgtrees(K, NULL);
  REP(i, K) sgtrees[i] = new SGTree(N);
  for(auto& j: arr){
    sgtrees[1]->update(0, 0, N-1, j-1, 1);
    for(int i=2; i<=k+1; i++){
      int v = sgtrees[i-1]->query(0, 0, N-1, 1-1, j-1-1);
      sgtrees[i]->update(0, 0, N-1, j-1, v);
    }
  }

  cout<<sgtrees[k+1]->query(0, 0, N-1, 0, N-1)<<endl;

  return 0;
}
