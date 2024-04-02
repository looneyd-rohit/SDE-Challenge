// https://cses.fi/problemset/task/1628/

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

void solve(int index, int sum, int n, vector<int>& arr, vector<int>& store){
  if(index >= n){
    store.push_back(sum);
    return;
  }

  // take
  solve(index+1, sum+arr[index], n, arr, store);
  // not take
  solve(index+1, sum, n, arr, store);
}

int binarySearchLeft(vector<int>& nums, int key){
  int n = nums.size();
  int low = 0, high = n - 1;
  while(low <= high){
    int mid = low + ((high - low) >> 1);
    if(nums[mid] >= key) high = mid - 1;
    else low = mid + 1;
  }
  return low;
}
int binarySearchRight(vector<int>& nums, int key){
  int n = nums.size();
  int low = 0, high = n - 1;
  while(low <= high){
    int mid = low + ((high - low) >> 1);
    if(nums[mid] <= key) low = mid + 1;
    else high = mid - 1;
  }
  return high;
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

  // Meet in the Middle
  // int t;
  // cin >> t;
  // while (t--){
    
  // }
  int n,x;
  cin>>n>>x;
  vector<int> arr(n);
  REP(i, n) cin>>arr[i];
  vector<int> left, right;
  for(int i=0; i<n/2; i++) left.push_back(arr[i]);
  for(int i=n/2; i<n; i++) right.push_back(arr[i]);
  // divide by two and compute
  vector<int> left_sums, right_sums;
  solve(0, 0, left.size(), left, left_sums);
  solve(0, 0, right.size(), right, right_sums);

  sort(begin(left_sums), end(left_sums));
  sort(begin(right_sums), end(right_sums));

  int count = 0;
  for(auto& sum: left_sums){
    int req_sum = x - sum;
    int l = binarySearchLeft(right_sums, req_sum);
    int r = binarySearchRight(right_sums, req_sum);
    if(l!=-1 && r!=-1){
      count += (r-l+1);
    }
  }
  cout<<count<<endl;


  return 0;
}
