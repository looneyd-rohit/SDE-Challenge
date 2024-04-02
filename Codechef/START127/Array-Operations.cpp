// https://www.codechef.com/problems/KIND

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ull unsigned long long
#define ll long long
#define REP(i, n) for (int(i) = 0; (i) < (n); (i)++)
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

bool isPossible(vector<int> &arr, int n, int k, int h)
{
  // think in a greedy fashion
  // for elements less than h, there can arise two cases
  // 1. div by k --> divide them and reduce as much possible
  // 2. not div by k --> try to make them >= h by multiplying only once
  // for elements greater than or equal to h, also two cases
  // 1. div by k --> divide them upto to a point such that it remains >= h
  // 2. not div by k --> don't do anything as we don't need any operation on it, it contributes already
  int count_of_good = 0, count_of_div = 0, count_of_multiply = 0;
  multiset<int> mst;
  REP(i, n)
  {
    int e = arr[i];
    if (e < h)
    {
      while ((e % k) == 0)
      {
        e /= k;
        count_of_div++;
      }

      if ((e * k) >= h)
      {
        count_of_multiply++;
      }
    }
    else
    {
      if(e % k == 0){
        while ((e % k == 0) && ((e / k) >= h))
        {
          e /= k;
          count_of_div++;
        }
        count_of_good++;
        
        int sacrifice = 0;
        while ((e % k) == 0)
        {
          e /= k;
          sacrifice++;
        }
        if (sacrifice >= 2)
          mst.insert(sacrifice);
      }else{
        // do nothing, it already contributes
        count_of_good++;
      }
    }
  }
  int possible = min(count_of_multiply, count_of_div);
  count_of_good += possible;
  count_of_multiply -= possible;
  count_of_div -= possible;
  // edge case where we check if decreasing a single
  // may result in increasing some other elements
  while (count_of_multiply >= 2 && !mst.empty())
  {
    int g = *mst.rbegin();
    mst.erase(mst.find(g));
    count_of_div += g;
    count_of_good--;

    int p = min(count_of_multiply, count_of_div);
    count_of_good += p;
    count_of_multiply -= p;
    count_of_div -= p;
  }
  return (count_of_good >= h);
}

int32_t main()
{
  nsync;
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("error.txt", "w", stderr);
#endif
  // Array Operations
  int t;
  cin >> t;
  while (t--)
  {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    REP(i, n)
        cin >> arr[i];
    int low = 1, high = 1e9;
    while (low <= high)
    {
      int mid = low + ((high - low) >> 1);
      if (isPossible(arr, n, k, mid))
      {
        low = mid + 1;
      }
      else
      {
        high = mid - 1;
      }
    }
    cout << high << endl;
  }
  return 0;
}
