// https://codeforces.com/contest/1955/problem/C

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
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    REP(i, n) cin>>a[i];
    // cout<<n<<endl;
    int low = 0, high = n-1;
    // cout<<low<<" and "<<high<<endl;
    int dir = 0;
    while(low < high){
      int mini = min(a[low], a[high]);
      if(dir == 0){
        // delete from left first
        if(mini == a[low]){
          if(k < (2*mini - 1)){
            break;
          }else{
            k = k - 2*mini + 1;
            a[low] = 0;
            a[high] = a[high] - mini + 1;
            dir = 1;
            low++;
          }
        }else{
          if(k < 2*mini){
            break;
          }else{
            k = k - 2*mini;
            a[high] = 0;
            a[low] = a[low] - mini;
            dir = 0;
            high--;
          }
        }
      }else{
        // delete from right first
        if(mini == a[high]){
          if(k < (2*mini - 1)){
            break;
          }else{
            k = k - 2*mini + 1;
            a[low] = a[low] - mini + 1;
            a[high] = 0;
            dir = 0;
            high--;
          }
        }else{
          if(k < 2*mini){
            break;
          }else{
            k = k - 2*mini;
            a[high] = a[high] - mini;
            a[low] = 0;
            dir = 1;
            low++;
          }
        }
      }
    }
    if(low == high && a[low]<=k){
      low++;
    }
    cout<<(n-(high-low+1))<<endl;

  }
  return 0; 
}