// https://codeforces.com/contest/1950/problem/E

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

const int N = 2e5+5;
vector<vector<int> > factors;
void precompute(){
  factors.resize(N);
  for(int i=1; i<N; i++){
    for(int j=i; j<N; j+=i){
      factors[j].push_back(i);
    }
  }
}

bool check(string& s, string& str){
  int n = s.length(), m = str.length();
  int cnt = 0;
  for(int i=0; i<n; i++){
    if(s[i]!=str[i%m]){
      cnt++;
    }
  }
  return (cnt <= 1);
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

  // E. Nearly Shortest Repeating Substring
  precompute();
  int t;
  cin >> t;
  while (t--){
    int n;
    cin>>n;
    string s;
    cin>>s;
    // since there can be only different index
    // hence, check only the first and second substrings
    // of length x; x being divisor of n
    int ans = n;
    for(auto& factor: factors[n]){
      string str1 = s.substr(0, factor);
      string str2 = s.substr(factor, factor);
      if(check(s, str1) || check(s, str2)){
        ans = factor;
        break;
      }
    }
    cout<<ans<<endl;
  }
  

  return 0;
}
