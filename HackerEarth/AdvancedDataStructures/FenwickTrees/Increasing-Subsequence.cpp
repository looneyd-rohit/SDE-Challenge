// https://www.hackerearth.com/practice/data-structures/advanced-data-structures/fenwick-binary-indexed-trees/practice-problems/algorithm/increasing-subsequence-1-2d4df2d3/

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

int binarySearch(vector<int>& nums, int val){
  int n = nums.size();
  int low = 0, high = n-1;
  while(low <= high){
    int mid = low + ((high - low) >> 1);
    if(nums[mid]==val) return mid;
    else if(nums[mid]<val) low = mid + 1;
    else high = mid - 1;
  }
  return -1;
}

class SGTree{
public:
  vector<int> segarr;
  SGTree(int n=0){
    this->segarr.resize(4*n+1, INF64);
  }
  void build(int index, int low, int high, vector<int>& arr){
    if(low==high){
      this->segarr[index] = arr[low];
      return;
    }
    int mid = low + ((high - low) >> 1);
    build(2*index+1, low, mid, arr);
    build(2*index+2, mid+1, high, arr);
    this->segarr[index] = min(this->segarr[2*index+1], this->segarr[2*index+2]);
  }
  void update(int index, int low, int high, int ind, int val){
    if(low == high){
      this->segarr[index] = min(this->segarr[index], val);
      return;
    }
    int mid = low + ((high - low) >> 1);
    if(ind <= mid){
      update(2*index+1, low, mid, ind, val);
    }else{
      update(2*index+2, mid+1, high, ind, val);
    }
    this->segarr[index] = min(this->segarr[2*index+1], this->segarr[2*index+2]);
  }
  int query(int index, int low, int high, int l, int r){
    // no overlap
    if(r<low || high<l) return INF64;

    // full overlap
    if(l<=low && high<=r) return this->segarr[index];

    // partial overlap
    int mid = low + ((high - low) >> 1);
    int left = query(2*index+1, low, mid, l, r);
    int right = query(2*index+2, mid+1, high, l, r);
    return min(left, right);
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

  // Increasing Subsequence
  // NOTE: comments are kept to build understanding

  // int t;
  // cin >> t;
  // while (t--){
    
  // }

  int n, k;
  cin>>n>>k;
  vector<int> arr(n);
  REP(i, n) cin>>arr[i];
  // dp approach:
  // dp[j][i] --> minimum element of the increasing subsequence
  // of length j ending at index i
  // vector<vector<int> > dp(k+1, vector<int>(n+1, INF64));
  // transitions:
  // dp[j][i] = min(arr[i], dp[j-1][0...i-1])
  // optimization:
  // use dp + segment trees (range minimum)
  vector<SGTree*> sgtrees;
  for(int i=0; i<=k+1; i++) sgtrees.push_back(new SGTree(n+1));
  vector<int> sorted_arr = arr;
  sort(begin(sorted_arr), end(sorted_arr));
  int ans = NINF;
  for(int i=0; i<n; i++){
    int ind = binarySearch(sorted_arr, arr[i]);
    // dp[1][ind] = arr[i];
    sgtrees[1]->update(0, 0, n-1, ind, arr[i]);
    for(int j=2; j<=k; j++){
      // int mini = INF64;
      // for(int l=0; l<ind; l++){
      //   mini = min(mini, dp[j-1][l]);
      // }
      // find minimum
      int mini = sgtrees[j-1]->query(0, 0, n-1, 0, ind-1);

      // dp[j][ind] = min(dp[j][ind], mini);

      // update minimum
      sgtrees[j]->update(0, 0, n-1, ind, mini);
    }
    // ans = max(ans, arr[i] - dp[k][ind]);
    ans = max(ans, arr[i] - sgtrees[k]->query(0, 0, n-1, 0, ind));
  }
  cout<<(ans<0?-1:ans)<<endl;

  return 0;
}
