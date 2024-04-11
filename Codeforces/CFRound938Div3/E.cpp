// https://codeforces.com/contest/1955/problem/E

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ull unsigned long long
#define ll long long
#define REP(i, n) for (int(i) = 0; (i) < (n); (i)++)
#define REPR(i, m, n) for (int(i) = (m); (i) < (n); (i)++)
#define REPRR(i, m, n) for (int(i) = (m); (i) > (n); (i)--)
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

bool isPossible(string& s, vector<int>& flips, int k){
  int n = s.length();
  // reset the number of flips at first
  fill(begin(flips), end(flips), 0);
  int open_flips = 0;
  for(int i=0; i<n; i++){
    // if flip was done at (i-k) window upto (i-1)
    // then it will be closed now
    if((i-k) >= 0 && flips[i-k]==1) open_flips--;

    if(open_flips & 1){
      // odd -> flip occurs
      if(s[i]=='1'){
        flips[i] = 1;
        open_flips++;
      }
    }else{
      // even -> no flip occurs
      if(s[i]=='0'){
        flips[i] = 1;
        open_flips++;
      }
    }

    // we cannot start a window at the last
    // where there are no more than k elements
    if((n-i) < k  && flips[i]==1){
      return false;
    }
  }
  return true;
}

int32_t main(){
  nsync;
  /*
  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
  #endif
  */

  // E. Long Inversions

  int t;
  cin >> t;
  while (t--){
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<int> flips(n, 0);
    REPRR(k, n, 0){
      if(isPossible(s, flips, k)){
        cout<<k<<endl;
        break;
      }
    }
  }
  return 0; 
}