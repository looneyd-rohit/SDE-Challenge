// https://codeforces.com/contest/1955/problem/D

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

  // D. Inaccurate Subsequence Search

  int t;
  cin >> t;
  while (t--){
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> a(n), b(m);
    REP(i, n) cin>>a[i];
    unordered_map<int, int> freq;
    REP(i, m){
      cin>>b[i];
      freq[b[i]]++;
    }
    int i=0, j=0;
    unordered_map<int, int> current_freq;
    int overlap = 0, count = 0;
    while(j < n){
      current_freq[a[j]]++;

      if(freq[a[j]] > 0 && (freq[a[j]] >= current_freq[a[j]])){
        overlap++;
      }

      if((j - i + 1) < m){
        j++;
      }else{
        if(overlap >= k) count++;

        // remove from overlap count only if
        // it was included
        if(freq[a[i]] > 0 && (freq[a[i]] >= current_freq[a[i]])) overlap--;
        current_freq[a[i]]--;

        i++;
        j++;
      }
    }
    cout<<(count)<<endl;
  }
  return 0; 
}